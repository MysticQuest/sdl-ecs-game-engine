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
	breezeAPI.AddInput(entity, CONTROL_SCHEME_XY, .5f);

	Entity entity1 = breezeAPI.AddEntity(); 
	std::wstring message1 = L"Added Entity with id: " + std::to_wstring(entity1) + L'\n'; 
	OutputDebugString(message1.c_str()); 
	breezeAPI.AddRenderer(entity1, "res/textures/pac1.png");
	breezeAPI.AddTranform(entity1, Vector2f(300, 300), Vector2f(.1f, .1f), 90, Vector2f(.5f, .3f)); 

	Entity entity2 = breezeAPI.AddEntity();
	std::wstring message2 = L"Added Entity with id: " + std::to_wstring(entity2) + L'\n';
	OutputDebugString(message2.c_str());
	breezeAPI.AddRenderer(entity2, "res/textures/pac1.png");
	breezeAPI.AddTranform(entity2, Vector2f(0, 500), Vector2f(.1f, -.1f), 90, Vector2f(.5f, .3f));
}

void World::Update()
{

}