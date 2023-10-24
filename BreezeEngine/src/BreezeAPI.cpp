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
    game->RegisterObserver(std::bind(&BreezeAPI::OnGameCoreUpdate, this, std::placeholders::_1));
}

BreezeAPI::~BreezeAPI() = default;

void BreezeAPI::Init()
{
    
}

void BreezeAPI::Run()
{
    game->Run(*sdl);
}

void BreezeAPI::RegisterGameUpdates(const std::function<void(int)>& update) {
    gameUpdates.push_back(update);
}

void BreezeAPI::OnGameCoreUpdate(int deltaTime) {
    for (auto& update : gameUpdates) {
        update(deltaTime);
    }
}

void BreezeAPI::GameOver()
{
    game->GameOver();
}

void BreezeAPI::RestartGame()
{
    game->RestartGame();
}


Entity BreezeAPI::AddEntity()
{
    Entity entity = create_entity();
    std::cout << "Created Entity with ID: " << entity << std::endl;
    return entity;
}

void BreezeAPI::AddTranform(Entity entity, Vector2f pos, Vector2f vel, float rot, Vector2f scale)
{
    ecs->AddComponent(entity, TransformComponent {
        pos,
        vel,
        rot,
        scale,
        });
}

void BreezeAPI::AddRenderer(Entity entity, const char* textureName)
{
    std::string path = "res/textures/" + std::string(textureName);
    SDL_Texture* texture = sdl->LoadTexture(path.c_str());
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

Vector2f BreezeAPI::GetPosition(Entity entity)
{
    TransformComponent transformComp = ecs->GetComponent<TransformComponent>(entity);
    return transformComp.position;
}

bool BreezeAPI::InputExists()
{
    return ecs->HasInputComponents();
}

bool BreezeAPI::DoesEntityExist(Entity entity)
{
    return ecs->DoesEntityExist(entity);
}

float BreezeAPI::Rng(float min, float max)
{
    return RNG::Int(min, max);
}

Vector2 BreezeAPI::GetWindowSize()
{
    return utils::GetWindowSize();
}
