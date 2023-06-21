#include "World.h"

World::World()
{
	BreezeAPI breezeAPI("settings.ini", "Test Title");
	breezeAPI.Run();
}