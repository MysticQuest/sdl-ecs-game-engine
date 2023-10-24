#pragma once
#include "MyMath.h"

struct CollisionComponent
{
    AABB aabb;
    bool isConstrained = true;
    bool canHitEnemies = true;
};