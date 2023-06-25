#pragma once

#include <SDL.h>
#include "MySDLWindow.h"
#include "ECS/Systems/RenderSystem.h"
#include "ECS/Systems/TransformSystem.h"
#include "ECS/Systems/InputSystem.h"
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

	ECSManager ecs;

private:
	std::vector<Entity> entities;
	int m_frame_rate = 0;
	bool isRunning = true;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	std::unique_ptr<RenderSystem> renderSystem;
	std::unique_ptr<TransformSystem> transformSystem;
	std::unique_ptr<InputSystem> inputSystem;
};