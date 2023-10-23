#include "Utils.h"

Vector2 utils::windowSizeEx(0, 0);

void utils::SetWindowSize(Vector2 newSize)
{
	windowSizeEx = newSize;
}

Vector2 utils::GetWindowSize()
{
	return windowSizeEx;
}
