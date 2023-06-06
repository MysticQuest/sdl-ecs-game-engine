#pragma once

#include <SDL.h>
#include "SDLWindow.h"
#include "SettingsResolver.h"
#include "Game.h"

class GameLauncher
{
public:
	GameLauncher(Game game);
	~GameLauncher();

	//void Render(SDLWindow&, Game const& game);
	//void PollEvents(SDLWindow&, bool& quit);
	//void Update();
	//void Run(SDLWindow& context, Game& game, int frame_rate);
};