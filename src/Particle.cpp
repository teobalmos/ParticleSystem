#include "Particle.h"

#include <iostream>

#define PI 3.14159265358979323846
#define MEDIUM_RADIUS 40
#define SMALL_RADIUS 10
#define BIG_RADIUS 60

void Particle::Move(int fps) {
	
	if (type == popped) {
		
	}
	else {

		float omega = PI / fps * rotation_modifier;

		float x1, z1;

		if (type == small) {
			x1 = init_x + SMALL_RADIUS * cos(theta);
			z1 = init_z + SMALL_RADIUS * sin(theta);
		}
		else if (type == medium) {
			x1 = init_x - MEDIUM_RADIUS * cos(theta);
			z1 = init_z - MEDIUM_RADIUS * sin(theta);
		}
		else {
			x1 = init_x + BIG_RADIUS * cos(theta);
			z1 = init_z + BIG_RADIUS * sin(theta);
		}

		x = x1;
		y -= speed;
		z = z1;

		theta += omega;
	}
}

bool Particle::isDead() {
	if (y <= maxHeight) {
		return true;
		std::cout << "height: " << y;
	}
	return false;
}

void Particle::Breathe() {

	if ( abs(init_radius - radius) > 3) {
		breathe_modifier *= -1;
	}

	radius += 0.2 * breathe_modifier;
}