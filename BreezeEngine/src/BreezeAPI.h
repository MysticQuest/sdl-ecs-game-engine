#include <memory>
#include <iostream>
#include <functional>
#include "MyMath.h"
#include "ECS/Entity.h"
#include "ControlSchemes.h"
#include "Export.h"
#include "Utils.h"

class SettingsResolver;
class MySDLWindow;
class GameCore;
class ECSManager;

class BreezeAPI
{
public:
    BREEZEENGINE_API BreezeAPI(const std::string& settingsFile, const char* title);
    BREEZEENGINE_API ~BreezeAPI();

    BREEZEENGINE_API void Init();
    BREEZEENGINE_API void Run();
    BREEZEENGINE_API void GameOver();
    BREEZEENGINE_API void RestartGame();

    BREEZEENGINE_API Entity AddEntity();
    BREEZEENGINE_API void AddTranform(Entity entity, Vector2f pos, Vector2f vel, float rot, Vector2f scale);
    BREEZEENGINE_API void AddRenderer(Entity entity, const char* texturePath);
    BREEZEENGINE_API void AddInput(Entity entity, int controlScheme, float inputSensitivity);
    BREEZEENGINE_API void AddCollision(Entity entity, bool isConstrained);

    BREEZEENGINE_API float Rng(float min, float max);
    BREEZEENGINE_API Vector2 GetWindowSize();
    BREEZEENGINE_API Vector2f GetPosition(Entity entity);
    BREEZEENGINE_API bool InputExists();
    BREEZEENGINE_API bool DoesEntityExist(Entity entity);

    BREEZEENGINE_API void RegisterGameUpdates(const std::function<void(int)>& update);

    void OnGameCoreUpdate(int deltaTime);

private:
    std::vector<std::function<void(int)>> gameUpdates;

    ECSManager* ecs;
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> sdl;
    std::unique_ptr<GameCore> game;
};
