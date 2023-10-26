#include "World.h"
#include <Windows.h>
#include <string>
#include "Utils.h"

World::World() : breezeAPI("engine.ini", "Sample Game 1")
{
	windowSize = breezeAPI.GetWindowSize();
	breezeAPI.RegisterGameUpdates(std::bind(&World::Update, this, std::placeholders::_1));
	breezeAPI.RegisterGameEvents([this](int eventFlag) {
		if (eventFlag & 1) 
		{
			this->PlayerFire();
		}
	});
	Init();
	breezeAPI.Run();
}

void World::Init()
{
	OutputDebugString(L"Initializing World...\n");

	AddPlayer();
	AddEnemies(3);
}

void World::AddPlayer()
{
	Entity playerEntity = breezeAPI.AddEntity();
	std::wstring message = L"Added Entity with id: " + std::to_wstring(playerEntity) + L'\n';
	OutputDebugString(message.c_str());
	breezeAPI.AddRenderer(playerEntity, "g0_player.png");
	breezeAPI.AddTranform(playerEntity, Vector2f(windowSize.X/2, windowSize.Y - 100), Vector2f(0, 0), 0, Vector2f(1, 1));
	breezeAPI.AddInput(playerEntity, CONTROL_SCHEME_XY, .2f);
	breezeAPI.AddCollision(playerEntity, true, false);
}

void World::AddEnemies(int count)
{
	for (int i = 0; i < count; i++)
	{
		entities.push_back(breezeAPI.AddEntity());
		Entity& lastEntity = entities.back();
		std::wstring message = L"Added Entity with id: " + std::to_wstring(lastEntity) + L'\n';
		OutputDebugString(message.c_str());
		breezeAPI.AddRenderer(lastEntity, "g0_enemy.png");
		breezeAPI.AddTranform(lastEntity, Vector2f(Rng(0, windowSize.X),Rng(0, windowSize.Y * 0.3f)), Vector2f(Rng(-5, 5), Rng(-3, 3)), 0, Vector2f(1, 1));
		breezeAPI.AddCollision(lastEntity, true, false);
	}
}

void World::FireProjectile() {
	for (const Entity entity : entities) {
		projectiles.push_back(breezeAPI.AddEntity());
		Entity& lastEntity = projectiles.back();
		std::wstring message = L"Added Projectile with id: " + std::to_wstring(lastEntity) + L'\n';
		OutputDebugString(message.c_str());
		breezeAPI.AddRenderer(lastEntity, "g0_shotRed.png");
		Vector2f spawnPoint = breezeAPI.GetPosition(entity);
		breezeAPI.AddTranform(lastEntity, spawnPoint, Vector2f(0, 15), 90, Vector2f(1, 1));
		breezeAPI.AddCollision(lastEntity, false, false);
	}
}

void World::PlayerFire()
{
	projectiles.push_back(breezeAPI.AddEntity());
	Entity& lastEntity = projectiles.back();
	std::wstring message = L"Added Projectile with id: " + std::to_wstring(lastEntity) + L'\n';
	OutputDebugString(message.c_str());
	breezeAPI.AddRenderer(lastEntity, "g0_shotBlue.png");
	Vector2f spawnPoint = breezeAPI.GetPosition(1);
	breezeAPI.AddTranform(lastEntity, spawnPoint, Vector2f(0, -15), 270, Vector2f(1, 1));
	breezeAPI.AddCollision(lastEntity, false, true);
}

void World::Update(float deltaTime)
{
	elapsedTime += deltaTime;
	fireCooldown += deltaTime;

	if (elapsedTime >= 5000)
	{
		AddEnemies(3);
		elapsedTime = 0;
	}

	if (fireCooldown >= 2000)
	{
		FireProjectile();
		fireCooldown = 0;
	}

	auto it = std::remove_if(entities.begin(), entities.end(), [this](Entity entity) {
		return !breezeAPI.DoesEntityExist(entity);
		});
	entities.erase(it, entities.end());

	if (!breezeAPI.InputExists())
	{
		breezeAPI.GameOver();
	}
}

float World::Rng(float min, float max)
{
	return breezeAPI.Rng(min, max);
}