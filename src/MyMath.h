#pragma once
#include <iostream>
#include <random>

struct Vector2f
{
	Vector2f()
	:x(0.0f), y(0.0f) { }

	Vector2f(float x, float y)
	:x(x), y(y) { }

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};

class RNG
{
public:
	static int GenerateInt(int lower, int upper);
	static float GenerateFloat(float lower, float upper);

private:
	static std::mt19937& getGenerator();
};





