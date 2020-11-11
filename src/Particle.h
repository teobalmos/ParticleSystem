#pragma once
#include <cstdlib>
class Particle {
public:
	enum BubbleType { small, medium, big };

	int x, y, z;
	int init_x, init_y, init_z;
	float radius;
	BubbleType type;
	float theta;
	float speed;

	Particle() = default;

	Particle(int new_x, int new_y, int new_z) : x(new_x), y(new_y), z(new_z), 
												init_x(new_x), init_y(new_y), init_z(new_z)
	{
		theta = 0;

		radius = (double)(rand() % 20) + 5;
		
		if (radius <= 9) {
			type = small;
			speed = (1 / radius) * 35;
		}
		else if (radius > 9 && radius <= 20) {
			type = medium;
			speed = (1 / radius) * 30;
		}
		else {
			type = big;
		}
	}

	~Particle() = default;

	void Move(int fps);
};

