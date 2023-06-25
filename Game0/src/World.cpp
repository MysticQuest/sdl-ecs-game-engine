#include "World.h"

World::World()
{
	BreezeAPI breezeAPI("engine.ini", "Sample Game 1");
	breezeAPI.Run();
}