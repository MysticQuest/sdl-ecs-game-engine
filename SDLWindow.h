#pragma once
#include <SDL.h>

struct SDLWindow 
{
public:
	SDLWindow(const char* title, std::size_t window_width, std::size_t window_height);
	~SDLWindow();
	void Clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};