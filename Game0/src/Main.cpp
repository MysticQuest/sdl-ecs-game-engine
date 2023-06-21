#include "BreezeAPI.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	    BreezeAPI breezeAPI("settings.ini", "Test Title");
	    breezeAPI.Run();
	
	    return 0;
}
