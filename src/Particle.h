#pragma once
#include <cstdlib>
#include <iostream>

class Particle {
public:
	enum BubbleType { small, medium, big, popped };

	int x, y, z;
	int init_x, init_y, init_z;
	float radius, init_radius;
	BubbleType type;
	float theta;
	float speed;
	float maxHeight;
	int breathe_modifier;

	Particle() = default;

	Particle(int new_x, int new_y, int new_z, BubbleType bubble_type = small) :
										x(new_x), y(new_y), z(new_z), 
										init_x(new_x), init_y(new_y), init_z(new_z)
	{
		theta = 0;

		// We give it the same characteristics as a small bubble.
		if (bubble_type == popped) {
			type = bubble_type;

			radius = (double)(rand() % 16) + 5;
			speed = (1 / radius) * 40;
						
			// The bubbless will go downwards for a bit.
			maxHeight = y + 150;

			// Theta will be used as time for the popped bubbles.
			theta = 0;
		}
		else {

			// A bubble will have the radius between 5 and 25.
			radius = (double)(rand() % 21) + 5;
			init_radius = radius;

			// The breathe_modifier will change wether a bubble increases
			// or decreases in size.
			breathe_modifier = rand() % 2 == 0 ? -1 : 1;

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

