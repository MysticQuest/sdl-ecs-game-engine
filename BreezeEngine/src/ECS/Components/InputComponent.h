#pragma once
#include <bitset>

struct InputComponent
{
	std::bitset<4> controlScheme = 0;
	float inputSensitivity = 0;
};