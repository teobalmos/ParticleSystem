#include "Particle.h"

#define PI 3.14159265358979323846
#define MEDIUM_RADIUS 40
#define SMALL_RADIUS 10

void Particle::Move(int fps) {
	float omega = PI / fps;

	if (type == small) {
		float x1 = init_x + SMALL_RADIUS * cos(theta);
		float z1 = init_z + SMALL_RADIUS * sin(theta);

		x = x1;
		y -= speed;
		z = z1;

		theta += omega;
	}
	else if (type == medium) {

		float x1 = init_x + MEDIUM_RADIUS * cos(theta);
		float z1 = init_z + MEDIUM_RADIUS * sin(theta);

		x = x1;
		y -= speed;
		z = z1;
		
		theta += omega;
	}
	else {

	}

}