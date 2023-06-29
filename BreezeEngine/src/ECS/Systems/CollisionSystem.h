#pragma once
#include "ECS/ECSManager.h"
#include "ECS/Components/CollisionComponent.h"
#include "ECS/Components/RenderComponent.h"

class CollisionSystem
{
public:
    void Update(ECSManager& ecs);

private:
    bool AABBcollision(const AABB& a, const AABB& b);
};
