#pragma once
#include <iostream>

struct Vector2f
{
	Vector2f()
	:m_x(0.0f), m_y(0.0f) { }

	Vector2f(float x, float y)
	:m_x(x), m_y(y) { }

	void print()
	{
		std::cout << m_x << ", " << m_y << std::endl;
	}

	float m_x, m_y;
};