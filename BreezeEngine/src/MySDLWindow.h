#pragma once

#include <SDL.h>
#include <SDL_image.h>
//#include "ECS/ECSManager.h"
#include "ECS/Systems/RenderSystem.h"

struct MySDLWindow
{
public:
	MySDLWindow(const char* title, int window_width, int window_height);
	~MySDLWindow();

	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Render(ECSManager& ecs);
	void Display();
	void Clean();

	SDL_Renderer* GetRenderer()
	{
		return renderer;
	}

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	RenderSystem* renderSystem;
};