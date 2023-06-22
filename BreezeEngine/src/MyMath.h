#pragma once
#include <iostream>
#include <random>

struct Vector2f
{
	Vector2f()
	:X(0.0f), Y(0.0f) { }

	Vector2f(float x, float y)
	:X(x), Y(y) { }

	inline Vector2f operator+(const Vector2f& other) const
	{
		return Vector2f(X + other.X, Y + other.Y);
	}

	inline Vector2f operator-(const Vector2f& other) const
	{
		return Vector2f(X - other.X, Y - other.Y);
	}

	inline Vector2f operator*(const float scalar) const
	{
		return Vector2f(X * scalar, Y * scalar);
	}

	void print()
	{
		std::cout << X << ", " << Y << std::endl;
	}

	float X, Y;
};

struct Vector2
{
	Vector2()
		:X(0), Y(0) { }

	Vector2(int x, int y)
		:X(x), Y(y) { }

	inline Vector2 operator+(const Vector2& other) const
	{
		return Vector2(X + other.X, Y + other.Y);
	}

	inline Vector2 operator-(const Vector2& other) const
	{
		return Vector2(X - other.X, Y - other.Y);
	}

	inline Vector2 operator*(const int scalar) const
	{
		return Vector2(X * scalar, Y * scalar);
	}

	void print()
	{
		std::cout << X << ", " << Y << std::endl;
	}

	int X, Y;
};

struct Transform
{
	Transform(float x, float y)
		:X(x), Y(y) { }

	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float x) { Y += x; }
	inline void Translate(Vector2f vectorF) { X += vectorF.X; Y += vectorF.Y; }

	float X, Y;
};

class RNG
{
public:
	static int Int(int lower, int upper);
	static float Float(float lower, float upper);

private:
	static std::mt19937& getGenerator();
};
