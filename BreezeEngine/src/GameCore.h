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
	void Update();
	void Run(MySDLWindow& sdlWindow);

private:
	int m_frame_rate = 0;
	bool isRunning = true;
};