#include <SDL.h>
#include <iostream>
#include <memory>
#include "SettingsResolver.h"
#include "SDLWindow.h"
#include "Game.h"



Game* game = nullptr;
SettingsResolver* settings = nullptr;
std::string fileName = "settings.ini";

int main(int argc, char* argv[])
{
    settings = new SettingsResolver();
    Config config = settings->ReadSettings(fileName);

    std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>(
        "Test Title",
        config.width,
        config.height);

    Game game(std::move(window), 60);

    return 0;
}
