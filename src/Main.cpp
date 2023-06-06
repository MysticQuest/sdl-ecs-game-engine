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

    SDLWindow window(
        "Test Title",
        config.width,
        config.height);

    SDL_Texture* testTexture = window.LoadTexture("res/textures/pac1.png");

    Game game(window, config.frame_rate);

    return 0;
}
