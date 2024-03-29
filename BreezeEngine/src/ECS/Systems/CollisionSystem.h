#pragma once
#include "ECS/ECSManager.h"
#include "ECS/Components/CollisionComponent.h"
#include "ECS/Components/RenderComponent.h"
#include "ECS/Components/TransformComponent.h"
#include <set>
#include <unordered_set>

class CollisionSystem
{
public:
    CollisionSystem(SDL_Renderer* renderer);
    void Update(ECSManager& ecs);

private:
    bool AABBcollision(const AABB& a, const AABB& b);
    bool PixelCollision(SDL_Texture* texture1, SDL_Rect rect1, SDL_Texture* texture2, SDL_Rect rect2);
    bool PixelIsSolid(SDL_Texture* texture, int x, int y);

    void SyncEntityRenderAndAABB(ECSManager& ecs);
    void CheckCollisions(ECSManager& ecs, std::unordered_set<size_t>& entitiesToDestroy);
    void DestroyEntities(ECSManager& ecs, std::unordered_set<size_t>& entitiesToDestroy);

    SDL_Renderer* m_renderer;
};
