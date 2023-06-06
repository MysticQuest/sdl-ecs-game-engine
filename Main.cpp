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

    std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>(
        "Test Title",
        config.width,
        config.height);

    Game game(std::move(window), config.frame_rate);

    return 0;
}
