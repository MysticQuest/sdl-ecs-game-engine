#include <iostream>
#include "SDLWindow.h"

SDLWindow::SDLWindow(const char* title, int window_width, int window_height)
:window(nullptr), renderer(nullptr)
{
	window = SDL_CreateWindow
	(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		window_width,
		window_height,
		SDL_WINDOW_SHOWN
	);
	if (window == nullptr) { std::cout << "Window creation failed: " << SDL_GetError() << std::endl; }

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) { std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl; }
}

SDL_Texture* SDLWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == nullptr)
	{
		std::cout << "Texture loading failed" << SDL_GetError() << std::endl;
	}

	return texture;
}

void SDLWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void SDLWindow::Render(SDL_Texture* texture)
{
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	SDL_Rect dstRect;
	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.w = 32;
	dstRect.h = 32;

	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}

void SDLWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void SDLWindow::Clean()
{
	SDL_DestroyWindow(window);
}

SDLWindow::~SDLWindow()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}