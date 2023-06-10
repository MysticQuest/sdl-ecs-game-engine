#include <memory>
#include <iostream>
#include "Export.h"

class SettingsResolver;
class MySDLWindow;
class GameCore;

class BREEZEENGINE_API BreezeAPI
{
public:
    BreezeAPI(const std::string& settingsFile, const char* title);
    ~BreezeAPI();
    void Run();

private:
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> window;
    std::unique_ptr<GameCore> game;
};
