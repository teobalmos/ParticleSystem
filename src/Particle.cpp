#include "Particle.h"

#include <iostream>

#define MEDIUM_RADIUS 40
#define SMALL_RADIUS 10
#define BIG_RADIUS 60

void Particle::Move() {
	
	if (type == popped) {
		speed += 0.1;
		x += cos(theta);
		z += sin(theta);
		y += powf(speed, 3) / 8;
	}
	else {

		float omega = PI / 60 * rotation_modifier;

		float x1, z1;

		if (type == small) {
			x1 = init_x + SMALL_RADIUS * cos(theta);
			z1 = init_z + SMALL_RADIUS * sin(theta);
		}
		else if (type == medium) {
			x1 = init_x + MEDIUM_RADIUS * cos(theta);
			z1 = init_z + MEDIUM_RADIUS * sin(theta);
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
	if (type == popped) {
		if (y >= maxHeight) {
			return true;
		}
	}
	else {
		if (y <= maxHeight) {
			return true;
		}
	}
	return false;
}

void Particle::Breathe() {

	if (abs(init_radius - radius) > 3) {
		breathe_modifier *= -1;
	}

	radius += 0.2 * breathe_modifier;
}