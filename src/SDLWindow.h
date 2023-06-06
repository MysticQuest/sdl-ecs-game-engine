#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"

struct SDLWindow 
{
public:
	SDLWindow(const char* title, int window_width, int window_height);
	~SDLWindow();

	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Render(Entity& entity);
	void Display();
	void Clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};