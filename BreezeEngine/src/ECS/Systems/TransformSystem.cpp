#include "TransformSystem.h"
#include <Utils.h>

void TransformSystem::Update(ECSManager& ecs, int deltaTime)
{
    Vector2 windowSize = utils::GetWindowSize();

    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.transformComponents.contains(e))
        {
            ecs.transformComponents[e].position.X += ecs.transformComponents[e].velocity.X * deltaTime;
            ecs.transformComponents[e].position.Y += ecs.transformComponents[e].velocity.Y * deltaTime;
        }

        if (ecs.transformComponents[e].position.X > static_cast<float>(windowSize.X) - 100)
        {
            ecs.transformComponents[e].position.X = static_cast<float>(windowSize.X) - 100;
        }
        else if (ecs.transformComponents[e].position.X < 0)
        {
            ecs.transformComponents[e].position.X = 0;
        }

        if (ecs.transformComponents[e].position.Y > static_cast<float>(windowSize.Y) - 100)
        {
            ecs.transformComponents[e].position.Y = static_cast<float>(windowSize.Y) - 100;
        }
        else if (ecs.transformComponents[e].position.Y < 30)
        {
            ecs.transformComponents[e].position.Y = 30;
        }
    }
}
