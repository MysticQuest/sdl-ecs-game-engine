#include "World.h"
#include <Windows.h>
#include <string>

World::World() : breezeAPI("engine.ini", "Sample Game 1")
{
	Init();
	breezeAPI.Run();
}

void World::Init()
{
	OutputDebugString(L"Initializing World...\n");
	Entity entity = breezeAPI.AddEntity();
	std::wstring message = L"Added Entity with id: " + std::to_wstring(entity) + L'\n';
	OutputDebugString(message.c_str());
	breezeAPI.AddRenderer(entity, "res/textures/pac1.png");
	breezeAPI.AddTranform(entity, Vector2f(300, 300), Vector2f(0, 0), 90, Vector2f(1.5, 0.5f));
	breezeAPI.AddInput(entity, CONTROL_SCHEME_X);
}

void World::Update()
{

}