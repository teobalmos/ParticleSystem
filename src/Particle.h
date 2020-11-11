#pragma once
class Particle
{
private:
	int x, y, z;

public:

	Particle() = default;

	Particle(float new_x, float new_y, float new_z) : x(new_x), y(new_y), z(new_z) 
	{}

	~Particle() = default;

	void Move() {
		y += 5;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}
};

