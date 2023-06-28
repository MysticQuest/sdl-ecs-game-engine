#include <memory>
#include <iostream>
#include "MyMath.h"
#include "ECS/Entity.h"
#include "ControlSchemes.h"
#include "Export.h"

class SettingsResolver;
class MySDLWindow;
class GameCore;
class ECSManager;

class BREEZEENGINE_API BreezeAPI
{
public:
    BreezeAPI(const std::string& settingsFile, const char* title);
    ~BreezeAPI();

    void Init();
    void Run();
    
    Entity AddEntity();
    void AddTranform(Entity entity, Vector2f pos, Vector2f vel, Vector2 scale);
    void AddRenderer(Entity entity, const char* texturePath);
    void AddInput(Entity entity, int controlScheme);

private:
    ECSManager* ecs;
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> sdl;
    std::unique_ptr<GameCore> game;
};
