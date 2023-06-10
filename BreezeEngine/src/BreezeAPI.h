#include "SettingsResolver.h"
#include "MySDLWindow.h"
#include "GameCore.h"
#include "Export.h"

class BREEZEENGINE_API BreezeAPI
{
public:
    BreezeAPI(const std::string& settingsFile, const char* title);
    void Run();

private:
    std::unique_ptr<SettingsResolver> settings;
    std::unique_ptr<MySDLWindow> window;
    std::unique_ptr<GameCore> game;
};
