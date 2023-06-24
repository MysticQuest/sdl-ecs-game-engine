#include "TransformSystem.h"

void TransformSystem::Update(ECSManager& ecs, int deltaTime)
{
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.transformComponents.contains(e))
        {
            ecs.transformComponents[e].position.X += ecs.transformComponents[e].velocity.X * deltaTime;
            ecs.transformComponents[e].position.Y += ecs.transformComponents[e].velocity.Y * deltaTime;
        }
    }
}
