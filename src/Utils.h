#pragma once

#include <SDL.h>

inline float GetTimeInSeconds()
{
	float t = SDL_GetTicks();
	t *= 0.001f;
	return t;
}