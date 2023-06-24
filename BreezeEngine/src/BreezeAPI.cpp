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

//void BreezeAPI::AddEntity(Transform transform, int width, int height, Vector2f velocity, SDL_Texture* texture, int flip)
//{
//    SDL_RendererFlip sdlFlip = static_cast<SDL_RendererFlip>(flip);
//    game->AddEntity(transform, width, height, velocity, texture, sdlFlip);
//}
