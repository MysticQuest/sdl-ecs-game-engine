#pragma once
#include <SDL.h>

struct SDLWindow 
{
public:
	SDLWindow(const char* title, std::size_t window_width, std::size_t window_height);
	~SDLWindow();
	void Clean();
	bool Running() { return isRunning; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
};