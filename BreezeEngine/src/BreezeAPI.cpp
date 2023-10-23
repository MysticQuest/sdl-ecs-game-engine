#include "SettingsResolver.h"
#include "MySDLWindow.h"
#include "GameCore.h"
#include "ECS/ECSManager.h"
#include "BreezeAPI.h"

BreezeAPI::BreezeAPI(const std::string& settingsFile, const char* title)
{
    settings = std::make_unique<SettingsResolver>();
    Config config = settings->ReadSettings(settingsFile);
    sdl = std::make_unique<MySDLWindow>(title, config.width, config.height);
    game = std::make_unique<GameCore>(*sdl, config.frame_rate);
    ecs = &(game->ecs);
}

BreezeAPI::~BreezeAPI() = default;

void BreezeAPI::Init()
{
   
}

void BreezeAPI::Run()
{
    game->Run(*sdl);
}

Entity BreezeAPI::AddEntity()
{
    Entity entity = create_entity();
    std::cout << "Created Entity with ID: " << entity << std::endl;
    return entity;
}

void BreezeAPI::AddTranform(Entity entity, Vector2f pos, Vector2f vel, float rot, Vector2f scale)
{
    ecs->AddComponent(entity, TransformComponent{
        pos,
        vel,
        rot,
        scale,
        });
}

void BreezeAPI::AddRenderer(Entity entity, const char* texturePath)
{
    SDL_Texture* texture = sdl->LoadTexture(texturePath);
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    ecs->AddComponent(entity, RenderComponent{
        SDL_Rect{ 0, 0, textureWidth, textureHeight },
        SDL_Rect{ 0, 0, textureWidth, textureHeight },
        texture,
        });
}

void BreezeAPI::AddInput(Entity entity, int controlScheme, float inputSensitivity)
{
    InputComponent inputComponent;
    inputComponent.controlScheme = controlScheme;
    inputComponent.inputSensitivity = inputSensitivity;
    ecs->AddComponent(entity, inputComponent);
}

void BreezeAPI::AddCollision(Entity entity, bool isConstrained)
{
    ecs->AddComponent(entity, CollisionComponent{ .isConstrained = isConstrained });
}

