#pragma once
class Particle
{
private:
	// float because double takes double the space
	float x, y, z;

public:

	Particle() = default;

	Particle(float new_x, float new_y, float new_z) : x(new_x), y(new_y), z(new_z) 
	{}

	~Particle() = default;

	void Move() {
		y += 5;
	}

	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getZ() {
		return z;
	}
};

