#include "BreezeAPI.h"

int main(int argc, char* argv[])
{
    BreezeAPI breezeAPI("settings.ini", "Test Title");
    breezeAPI.Run();

    return 0;
}
