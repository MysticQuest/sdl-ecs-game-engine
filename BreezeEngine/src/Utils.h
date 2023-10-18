#pragma once
#include <SDL.h>
#include <MySDLWindow.h>

namespace utilData
{
	inline Vector2 windowSize = Vector2(0, 0);

	inline void SetWindowSize(Vector2 newSize)
	{
		windowSize = newSize;
	}
}

namespace utils
{
	inline float GetTimeInSeconds()
	{
		float t = (float)SDL_GetTicks();
		t *= 0.001f;
		return t;
	}

	inline Vector2 GetWindowSize()
	{
		return utilData::windowSize;
	}
}
