#pragma once

#include <SDL.h>
#include "SettingsResolver.h"

class Game 
{
public:
	Game();
	~Game();

	void Initialize(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running() { return isRunning; }

private:
	int frameCounter = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};