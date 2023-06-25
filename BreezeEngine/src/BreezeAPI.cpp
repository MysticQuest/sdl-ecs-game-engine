#include "SettingsResolver.h"
#include "MySDLWindow.h"
#include "GameCore.h"
#include "ECS/Entity.h"
#include "ECS/ECSManager.h"
#include "BreezeAPI.h"

BreezeAPI::BreezeAPI(const std::string& settingsFile, const char* title)
{
    settings = std::make_unique<SettingsResolver>();
    Config config = settings->ReadSettings(settingsFile);
    window = std::make_unique<MySDLWindow>(title, config.width, config.height);
    game = std::make_unique<GameCore>(*window, config.frame_rate);
    ecs = std::make_unique<ECSManager>();
}

BreezeAPI::~BreezeAPI() = default;

void BreezeAPI::Init()
{
   
}

void BreezeAPI::Run()
{
    game->Run(*window);
}
