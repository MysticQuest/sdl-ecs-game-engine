#pragma once
#include <SDL.h>
#include <SDL_image.h>

struct SDLWindow 
{
public:
	SDLWindow(const char* title, int window_width, int window_height);
	~SDLWindow();

	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Render(SDL_Texture* texture);
	void Display();
	void Clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};