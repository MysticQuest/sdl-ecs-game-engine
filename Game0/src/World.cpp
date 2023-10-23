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

	AddPlayer();

	Entity entity1 = breezeAPI.AddEntity(); 
	std::wstring message1 = L"Added Entity with id: " + std::to_wstring(entity1) + L'\n'; 
	OutputDebugString(message1.c_str()); 
	breezeAPI.AddRenderer(entity1, "pac1.png");
	breezeAPI.AddTranform(entity1, Vector2f(300, 100), Vector2f(.1f, .1f), 0, Vector2f(2, 2));
	breezeAPI.AddCollision(entity1, false);

	Entity entity2 = breezeAPI.AddEntity();
	std::wstring message2 = L"Added Entity with id: " + std::to_wstring(entity2) + L'\n';
	OutputDebugString(message2.c_str());
	breezeAPI.AddRenderer(entity2, "pac1.png");
	breezeAPI.AddTranform(entity2, Vector2f(300, 300), Vector2f(0, 0), 0, Vector2f(1, 1));
	breezeAPI.AddCollision(entity2, true);
}

void World::AddPlayer()
{
	Entity entity = breezeAPI.AddEntity();
	std::wstring message = L"Added Entity with id: " + std::to_wstring(entity) + L'\n';
	OutputDebugString(message.c_str());
	breezeAPI.AddRenderer(entity, "pac1.png");
	breezeAPI.AddTranform(entity, Vector2f(300, 500), Vector2f(0, 0), 0, Vector2f(1, 1));
	breezeAPI.AddInput(entity, CONTROL_SCHEME_XY, .1f);
	breezeAPI.AddCollision(entity, true);
}

void World::Update()
{

}