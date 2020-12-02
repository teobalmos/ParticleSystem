#pragma once
#include <cstdlib>
#include <iostream>
#include "ofColor.h"

#define PI 3.14159265358979323846

const std::vector<ofColor> predefined_colours{ {161, 255, 250}, { 178, 161, 255 }, {230, 161, 255},  
	{255, 161, 200}, {255, 200, 161}, {161, 183, 255}, {255, 249, 161} };

class Particle {
public:
	enum BubbleType { small, medium, big, popped };

	double x, y, z;
	int init_x, init_y, init_z;
	float radius, init_radius;
	BubbleType type;
	float theta;
	float speed;
	float maxHeight;
	int breathe_modifier, rotation_modifier;
	ofColor colour;

	Particle() = default;

	Particle(double new_x, double new_y, double new_z, 
		double new_radius = 0, BubbleType bubble_type = small) :
										x(new_x), y(new_y), z(new_z), 
										init_x(new_x), init_y(new_y), init_z(new_z)
	{
		theta = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2 * PI)));

		// The breathe_modifier will change wether a bubble increases
		// or decreases in size.
		breathe_modifier = rand() % 2 == 0 ? -1 : 1;

		// The rotation_modifier decides whether the bubble rotates 
		// clockwise or counter-clockwise.
		rotation_modifier = rand() % 2 == 0 ? -1 : 1;

		colour = predefined_colours.at(rand() % predefined_colours.size());

		// We give it the same characteristics as a small bubble.
		if (bubble_type == popped) {
			type = bubble_type;

			radius = new_radius / 3;
			init_radius = radius;
			speed = 0;
						
			// The bubbless will go downwards for a bit.
			maxHeight = y + 150;
		}
		else {

			// A bubble will have the radius between 5 and 25.
			radius = (double)(rand() % 21) + 5;
			init_radius = radius;

			// The size of the bubble determines its characteristics.
			// There are three types of bubble motions.
			// The small ones move almost in a straight line, while the
			// middle in big ones have a helical motion.
			// The small bubbless move faster than the bigger bubbles.
			// http://www.seas.ucla.edu/stenstro/Bubble.pdf
			if (radius <= 9) {
				type = small;
				speed = (1 / radius) * 40;
			}
			else if (radius > 9 && radius <= 20) {
				type = medium;
				speed = (1 / radius) * 36;
			}
			else {
				type = big;
				speed = (1 / radius) * 32;
			}
			maxHeight = -(1 / radius) * 2400;
		}
	}

	~Particle() = default;

	void Move(int fps);
	bool isDead();
	void Breathe();
};

