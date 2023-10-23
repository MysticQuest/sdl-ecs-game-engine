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
	void AddPlayer();
	void Update(int deltaTime);
	int elapsedTime = 0;
};