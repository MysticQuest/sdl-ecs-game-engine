#pragma once

#include "../../MyMath.h"

struct TransformComponent
{
	Vector2f position;
	Vector2f velocity;
	float rotation = 0.0f;
	Vector2f scale { 1, 1 };
};