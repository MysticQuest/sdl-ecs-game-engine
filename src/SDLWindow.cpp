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

void SDLWindow::Render(const Entity& entity)
{
	SDL_Rect srcRect;
	srcRect.x = entity.GetRect().x;
	srcRect.y = entity.GetRect().y;
	srcRect.w = entity.GetRect().w;
	srcRect.h = entity.GetRect().h;

	SDL_Rect dstRect;
	dstRect.x = entity.GetPos().x;
	dstRect.y = entity.GetPos().y;
	dstRect.w = entity.GetRect().w;
	dstRect.h = entity.GetRect().h;

	SDL_RenderCopy(renderer, entity.GetTexture(), &srcRect, &dstRect);
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