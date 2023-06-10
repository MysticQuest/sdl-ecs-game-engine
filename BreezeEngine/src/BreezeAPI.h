#include "Export.h"
#include <string>
#include <memory>

class BreezeAPIImpl; // forward declaration

class BREEZEENGINE_API BreezeAPI
{
public:
    BreezeAPI(const std::string& settingsFile, const char* title);
    ~BreezeAPI();

    void Run();

private:
    std::unique_ptr<BreezeAPIImpl> pImplementation;
};

