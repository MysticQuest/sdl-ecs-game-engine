#include "World.h"
#include <Windows.h>
#include <string>
#include "Utils.h"

World::World() : breezeAPI("engine.ini", "Sample Game 1")
{
	Init();
	windowSize = breezeAPI.GetWindowSize();
	breezeAPI.RegisterGameUpdates(std::bind(&World::Update, this, std::placeholders::_1));
	breezeAPI.Run();
}

void World::Init()
{
	OutputDebugString(L"Initializing World...\n");

	AddPlayer();
	AddEnemies(1);

	//Entity entity2 = breezeAPI.AddEntity();
	//std::wstring message2 = L"Added Entity with id: " + std::to_wstring(entity2) + L'\n';
	//OutputDebugString(message2.c_str());
	//breezeAPI.AddRenderer(entity2, "pac1.png");
	//breezeAPI.AddTranform(entity2, Vector2f(300, 300), Vector2f(0, 0), 0, Vector2f(1, 1));
	//breezeAPI.AddCollision(entity2, true);
}

void World::AddPlayer()
{
	Entity playerEntity = breezeAPI.AddEntity();
	std::wstring message = L"Added Entity with id: " + std::to_wstring(playerEntity) + L'\n';
	OutputDebugString(message.c_str());
	breezeAPI.AddRenderer(playerEntity, "pac1.png");
	breezeAPI.AddTranform(playerEntity, Vector2f(windowSize.X/2, windowSize.Y), Vector2f(0, 0), 0, Vector2f(1, 1));
	breezeAPI.AddInput(playerEntity, CONTROL_SCHEME_XY, .1f);
	breezeAPI.AddCollision(playerEntity, true);
}

void World::AddEnemies(int count)
{
	for (int i = 0; i < count; i++)
	{
		entities.push_back(breezeAPI.AddEntity());
		Entity& lastEntity = entities.back();
		std::wstring message = L"Added Entity with id: " + std::to_wstring(lastEntity) + L'\n';
		OutputDebugString(message.c_str());
		breezeAPI.AddRenderer(lastEntity, "pac1.png");
		breezeAPI.AddTranform(lastEntity, Vector2f(Rng(0, windowSize.X), Rng(0, 100)), Vector2f(Rng(0.05f, .5f), Rng(0.05f, 0.1f)), 0, Vector2f(1, 1));
		breezeAPI.AddCollision(lastEntity, true);
	}
}

void World::Fire(Entity entity)
{
	breezeAPI.AddEntity();
}

void World::Update(int deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime >= 5000)
	{
		AddEnemies(1);
		elapsedTime = 0;
	}
}

float World::Rng(float min, float max)
{
	return breezeAPI.Rng(min, max);
}