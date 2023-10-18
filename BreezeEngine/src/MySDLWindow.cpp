#include <iostream>
#include "MySDLWindow.h"
#include <Utils.h>

MySDLWindow::MySDLWindow(const char* title, int window_width, int window_height)
:window(nullptr), renderer(nullptr), renderSystem(nullptr)
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) { std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl; }

	utilData::SetWindowSize(Vector2(window_width, window_height));
}

SDL_Texture* MySDLWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == nullptr)
	{
		std::cout << "Texture loading failed" << SDL_GetError() << std::endl;
	}

	return texture;
}

void MySDLWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void MySDLWindow::Render(ECSManager& ecs)
{
	renderSystem->Render(ecs, renderer);
}

void MySDLWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void MySDLWindow::Clean()
{
	SDL_DestroyWindow(window);
}

MySDLWindow::~MySDLWindow()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}