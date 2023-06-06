#include <SDL.h>
#include <iostream>
#include <memory>
#include "SettingsResolver.h"
#include "SDLWindow.h"
#include "Game.h"

const std::string SETTINGS_FILE = "settings.ini";
SettingsResolver* settings = nullptr;
Game* game = nullptr;

int main(int argc, char* argv[])
{
    settings = new SettingsResolver();
    Config config = settings->ReadSettings(SETTINGS_FILE);

    SDLWindow sdlWindow(
        "Test Title",
        config.width,
        config.height);

    Game game(sdlWindow, config.frame_rate);

    return 0;
}
