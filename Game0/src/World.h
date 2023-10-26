#pragma once
#pragma warning(disable: 4244)

#include <windows.h>
#include <vector>
#include "BreezeAPI.h"

class World
{
public:
	World();
	BreezeAPI breezeAPI;

private:
	void Init();
	void Update(float deltaTime);

	void AddPlayer();
	void AddEnemies(int count);
	void FireProjectile();
	void PlayerFire();
	float Rng(float min, float max);
	Vector2 windowSize;

	int elapsedTime = 0;
	int fireCooldown = 0;
	std::vector<Entity> entities;
	std::vector<Entity> projectiles;
};