#pragma once
#include <cstdlib>
#include <iostream>

class Particle {
public:
	enum BubbleType { small, medium, big };

	int x, y, z;
	int init_x, init_y, init_z;
	float radius;
	BubbleType type;
	float theta;
	float speed;
	float maxHeight;

	Particle() = default;

	Particle(int new_x, int new_y, int new_z) : x(new_x), y(new_y), z(new_z), 
												init_x(new_x), init_y(new_y), init_z(new_z)
	{
		theta = 0;

		// A bubble will have the radius between 5 and 25.
		radius = (double)(rand() % 20) + 5;
		
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

	~Particle() = default;

	void Move(int fps);
	bool isDead();
};

