#pragma once

#include <SDL.h>
#include "SDLWindow.h"
#include "SettingsResolver.h"

class Game 
{
public:
	Game(SDLWindow sdlWindow, int frame_rate);
	~Game();

	void Render();
	void PollEvents(bool& quit);
	void Update();
	void Run();

private:
	int frame_rate = 0;
};