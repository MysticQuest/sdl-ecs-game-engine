#pragma once

#include <SDL.h>

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
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};