#pragma once
#include <iostream>
#include <random>

struct Vector2f
{
	Vector2f()
	:x(0.0f), y(0.0f) { }

	Vector2f(float x, float y)
	:x(x), y(y) { }

	inline Vector2f operator+(const Vector2f& other) const
	{
		return Vector2f(x + other.x, y + other.y);
	}

	inline Vector2f operator-(const Vector2f& other) const
	{
		return Vector2f(x - other.x, y - other.y);
	}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};

struct Vector2
{
	Vector2()
		:x(0), y(0)
	{
	}

	Vector2(int x, int y)
		:x(x), y(y)
	{
	}

	inline Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	inline Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	int x, y;
};

class RNG
{
public:
	static int Int(int lower, int upper);
	static float Float(float lower, float upper);

private:
	static std::mt19937& getGenerator();
};





