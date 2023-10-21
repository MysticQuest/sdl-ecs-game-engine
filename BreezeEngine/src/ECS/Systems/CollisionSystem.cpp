#include "CollisionSystem.h"
#include <set>

void CollisionSystem::Update(ECSManager& ecs)
{
    std::set<int> entitiesToDestroy;

    // Syncs entity render and aabb
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.collisionComponents.contains(e) && ecs.renderComponents.contains(e))
        {
            const SDL_Rect& dstRect = ecs.renderComponents[e].dstRect;
            ecs.collisionComponents[e].aabb = {
                static_cast<float>(dstRect.x),
                static_cast<float>(dstRect.y),
                static_cast<float>(dstRect.w),
                static_cast<float>(dstRect.h)
            };
        }
    }

    for (int e1 = 1; e1 <= max_entity; e1++)
    {
        if (ecs.collisionComponents.contains(e1) && ecs.renderComponents.contains(e1))
        {
            const AABB& box1 = ecs.collisionComponents[e1].aabb;

            for (int e2 = e1 + 1; e2 <= max_entity; e2++)
            {
                if (ecs.collisionComponents.contains(e2) && ecs.renderComponents.contains(e2))
                {
                    const AABB& box2 = ecs.collisionComponents[e2].aabb;

                    if (AABBcollision(box1, box2))
                    {
                        // Collision detected between entity e1 and entity e2
                        entitiesToDestroy.insert(e1);
                        entitiesToDestroy.insert(e2);
                    }
                }
            }
        }
    }

    for (int entityId : entitiesToDestroy)
    {
        ecs.DestroyEntity(entityId);
    }
}

bool CollisionSystem::AABBcollision(const AABB& a, const AABB& b)
{
    return (a.x < (b.x + b.width) &&
        (a.x + a.width) > b.x &&
        a.y < (b.y + b.height) &&
        (a.y + a.height) > b.y);
}