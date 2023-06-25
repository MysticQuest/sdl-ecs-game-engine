#include "World.h"

World::World() : breezeAPI("engine.ini", "Sample Game 1")
{
	Init();
	breezeAPI.Run();
}

void World::Init()
{
	Entity& entity = breezeAPI.AddEntity();
	breezeAPI.AddInput(entity);
	breezeAPI.AddRenderer(entity, "res/textures/pac1.png");
	breezeAPI.AddTranform(entity, Vector2f(300, 300), Vector2f(0, 0), Vector2(1, 1));
}

void World::Update()
{

}