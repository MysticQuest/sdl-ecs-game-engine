#pragma once

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
	void Update(int deltaTime);

	void AddPlayer();
	void AddEnemies(int count);
	void Fire(Entity entity);
	float Rng(float min, float max);
	Vector2 windowSize;

	int elapsedTime = 0;
	std::vector<Entity> entities;
};