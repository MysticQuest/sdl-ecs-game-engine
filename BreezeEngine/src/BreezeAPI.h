#include <memory>
#include <iostream>
#include "MyMath.h"
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
    void AddEntity();

private:
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> window;
    std::unique_ptr<GameCore> game;
    std::unique_ptr<ECSManager> ecs;
};
