#pragma once

#include <vector>
#include "BreezeAPI.h"

class World
{
public:
	World();

	BreezeAPI breezeAPI;

private:
	void Init();
	void Update();
};