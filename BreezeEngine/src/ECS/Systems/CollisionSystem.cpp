#include "CollisionSystem.h"

void CollisionSystem::Update(ECSManager& ecs)
{
    for (int e1 = 1; e1 <= max_entity; e1++)
    {
        if (ecs.collisionComponents.contains(e1) && ecs.renderComponents.contains(e1))
        {

            // Sync position and size from RenderComponent to CollisionComponent
            const SDL_Rect& dstRect = ecs.renderComponents[e1].dstRect;
            ecs.collisionComponents[e1].aabb = { (float)dstRect.x, (float)dstRect.y, (float)dstRect.w, (float)dstRect.h };

            for (int e2 = e1 + 1; e2 <= max_entity; e2++)
            {
                if (ecs.collisionComponents.contains(e2) && ecs.renderComponents.contains(e2))
                {

                    // Sync position and size from RenderComponent to CollisionComponent
                    const SDL_Rect& dstRect2 = ecs.renderComponents[e2].dstRect;
                    ecs.collisionComponents[e2].aabb = { 
                        static_cast<float>(dstRect2.x),
                        static_cast<float>(dstRect2.y), 
                        static_cast<float>(dstRect2.w), 
                        static_cast<float>(dstRect2.h)
                    };

                    const AABB& box1 = ecs.collisionComponents[e1].aabb;
                    const AABB& box2 = ecs.collisionComponents[e2].aabb;

                    if (AABBcollision(box1, box2))
                    {
                        // Collision detected between entity e1 and entity e2
                        // Handle collision
                    }
                }
            }
        }
    }
}

bool CollisionSystem::AABBcollision(const AABB& a, const AABB& b)
{
    return (a.x < (b.x + b.width) &&
        (a.x + a.width) > b.x &&
        a.y < (b.y + b.height) &&
        (a.y + a.height) > b.y);
}