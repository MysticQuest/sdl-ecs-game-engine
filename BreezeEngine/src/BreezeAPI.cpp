#include "SettingsResolver.h"
#include "MySDLWindow.h"
#include "GameCore.h"
#include "BreezeAPI.h"

BreezeAPI::BreezeAPI(const std::string& settingsFile, const char* title)
{
    settings = std::make_unique<SettingsResolver>();
    Config config = settings->ReadSettings(settingsFile);
    window = std::make_unique<MySDLWindow>(title, config.width, config.height);
    game = std::make_unique<GameCore>(*window, config.frame_rate);
}

BreezeAPI::~BreezeAPI() = default;

void BreezeAPI::Run()
{
    game->Run(*window);
}
