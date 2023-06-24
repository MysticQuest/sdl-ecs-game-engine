#pragma once

#include <SDL.h>
#include "MySDLWindow.h"
#include "Entity.h"
#include "MyMath.h"
#include "Utils.h"


class GameCore
{
public:
	GameCore(MySDLWindow& sdlWindow, int frame_rate);
	~GameCore();

	void Render(MySDLWindow& sdlWindow, const std::vector<Entity>& entities);
	void PollEvents();
	void Update(int deltaTime);
	void Run(MySDLWindow& sdlWindow);

	void AddEntity(Transform& transform, int width, int height, Vector2f velocity, SDL_Texture* texture, SDL_RendererFlip flip);

private:
	std::vector<Entity> entities;
	int m_frame_rate = 0;
	bool isRunning = true;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
};