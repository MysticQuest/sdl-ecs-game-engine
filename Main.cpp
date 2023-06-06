#include <SDL.h>
#include <iostream>
#include <memory>
#include "SettingsResolver.h"
#include "SDLWindow.h"
#include "Game.h"

SettingsResolver* settings = nullptr;
std::string fileName = "settings.ini";
Game* game = nullptr;

int main(int argc, char* argv[])
{
    settings = new SettingsResolver();
    Config config = settings->ReadSettings(fileName);

    std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>(
        "Test Title",
        config.width,
        config.height);

    Game game(std::move(window), config.frame_rate);

    return 0;
}
