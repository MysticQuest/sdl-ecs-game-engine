#pragma once
#include "MyMath.h"

struct CollisionComponent
{
    AABB aabb { 0, 0, 0, 0 };
    bool isConstrained = true;
    bool canHitEnemies = true;
};