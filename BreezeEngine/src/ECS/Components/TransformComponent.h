#pragma once

#include "../../MyMath.h"

struct TransformComponent
{
	Vector2f position;
	Vector2f velocity;
	Vector2f rotation;
	Vector2 scale { 1, 1 };
};