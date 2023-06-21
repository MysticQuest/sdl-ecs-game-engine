#include <memory>
#include <iostream>
#include "MyMath.h"
#include "Export.h"

class SettingsResolver;
class MySDLWindow;
class GameCore;
struct SDL_Texture;

class BREEZEENGINE_API BreezeAPI
{
public:
    BreezeAPI(const std::string& settingsFile, const char* title);
    ~BreezeAPI();
    void Run();

    void AddEntity(Transform transform, int width, int height, Vector2f velocity, SDL_Texture* texture, int flip);

private:
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> window;
    std::unique_ptr<GameCore> game;
};
