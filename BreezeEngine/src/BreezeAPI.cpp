#include "BreezeAPI.h"
#include "SettingsResolver.h"
#include "MySDLWindow.h"
#include "GameCore.h"
#include <memory>

class BreezeAPIImpl
{
public:
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> window;
    std::unique_ptr<GameCore> game;
};

BreezeAPI::BreezeAPI(const std::string& settingsFile, const char* title)
    : pImplementation(std::make_unique<BreezeAPIImpl>()) // Initialize the pImpl
{
    pImplementation->settings = std::make_unique<SettingsResolver>();
    Config config = pImplementation->settings->ReadSettings(settingsFile);
    pImplementation->window = std::make_unique<MySDLWindow>(title, config.width, config.height);
    pImplementation->game = std::make_unique<GameCore>(*pImplementation->window, config.frame_rate);
}

BreezeAPI::~BreezeAPI() = default;

void BreezeAPI::Run()
{
    pImplementation->game->Run(*pImplementation->window);
}
