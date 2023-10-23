#include "TransformSystem.h"
#include <Utils.h>

void TransformSystem::Update(ECSManager& ecs, int deltaTime)
{
    Vector2 windowSize = utils::GetWindowSize();

    for (auto& [e, transform] : ecs.transformComponents)
    {
        transform.position.X += transform.velocity.X * deltaTime * 0.01f;
        transform.position.Y += transform.velocity.Y * deltaTime * 0.01f;

        // if the entity also has a collision component, constrain it
        auto collisionIt = ecs.collisionComponents.find(e);
        if (collisionIt != ecs.collisionComponents.end())
        {
            auto& collisionComp = collisionIt->second;

            if (collisionComp.isConstrained == false) 
            { 
                continue; 
            }

            float entityWidth = collisionComp.aabb.width;
            float entityHeight = collisionComp.aabb.height;

            // constraint X
            if (transform.position.X > static_cast<float>(windowSize.X) - entityWidth)
            {
                transform.position.X = static_cast<float>(windowSize.X) - entityWidth;
            }
            else if (transform.position.X < 0)
            {
                transform.position.X = 0;
            }

            // constraint Y
            if (transform.position.Y > static_cast<float>(windowSize.Y) - entityHeight)
            {
                transform.position.Y = static_cast<float>(windowSize.Y) - entityHeight;
            }
            else if (transform.position.Y < 0)
            {
                transform.position.Y = 0;
            }
        }
    }
}
