#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(SDL_Renderer* renderer) : m_renderer(renderer) {}

void CollisionSystem::Update(ECSManager& ecs)
{
    SyncEntityRenderAndAABB(ecs);

    std::unordered_set<size_t> entitiesToDestroy;
    CollisionSystem::CheckCollisions(ecs, entitiesToDestroy);

    DestroyEntities(ecs, entitiesToDestroy);
}

void CollisionSystem::SyncEntityRenderAndAABB(ECSManager& ecs)
{
    for (auto& [e, collisionComp] : ecs.collisionComponents)
    {
        if (ecs.renderComponents.contains(e) && ecs.transformComponents.contains(e))
        {
            const SDL_Rect& dstRect = ecs.renderComponents[e].dstRect;
            const Vector2f& scale = ecs.transformComponents[e].scale;
            ecs.collisionComponents[e].aabb = {
                static_cast<float>(dstRect.x),
                static_cast<float>(dstRect.y),
                static_cast<float>(dstRect.w * scale.X),
                static_cast<float>(dstRect.h * scale.Y)
            };
        }
    }
}

void CollisionSystem::CheckCollisions(ECSManager& ecs, std::unordered_set<size_t>& entitiesToDestroy)
{
    if (ecs.inputComponents.empty())
    {
        return;
    }

    const size_t playerEntity = ecs.inputComponents.begin()->first;
    const AABB& playerBox = ecs.collisionComponents[playerEntity].aabb;

    auto it1 = ecs.collisionComponents.begin();
    while (it1 != ecs.collisionComponents.end())
    {
        const size_t e1 = it1->first;
        const AABB& box1 = it1->second.aabb;
        const bool canHitEnemies1 = it1->second.canHitEnemies;

        if (e1 != playerEntity && !canHitEnemies1 && AABBcollision(playerBox, box1))
        {
            entitiesToDestroy.insert(playerEntity);
            entitiesToDestroy.insert(e1);
        }

        auto it2 = std::next(it1);
        while (it2 != ecs.collisionComponents.end())
        {
            const size_t e2 = it2->first;
            const AABB& box2 = it2->second.aabb;
            const bool canHitEnemies2 = it2->second.canHitEnemies;

            if (e1 != playerEntity && e2 != playerEntity && (canHitEnemies1 || canHitEnemies2) && AABBcollision(box1, box2))
            {
                entitiesToDestroy.insert(e1);
                entitiesToDestroy.insert(e2);
            }
            ++it2;
        }
        ++it1;
    }
}

void CollisionSystem::DestroyEntities(ECSManager& ecs, std::unordered_set<size_t>& entitiesToDestroy)
{
    for (size_t entityId : entitiesToDestroy)
    {
        ecs.DestroyEntity(entityId);
    }
    entitiesToDestroy.clear();
}

bool CollisionSystem::AABBcollision(const AABB& a, const AABB& b)
{
    return (a.x < (b.x + b.width) && (a.x + a.width) > b.x && a.y < (b.y + b.height) && (a.y + a.height) > b.y);
}

bool CollisionSystem::PixelCollision(SDL_Texture* texture1, SDL_Rect rect1, SDL_Texture* texture2, SDL_Rect rect2)
{    
    int width1, height1, width2, height2;
    SDL_QueryTexture(texture1, NULL, NULL, &width1, &height1);
    SDL_QueryTexture(texture2, NULL, NULL, &width2, &height2);

    int top = std::max(rect1.y, rect2.y);
    int bottom = std::min(rect1.y + height1, rect2.y + height2);
    int left = std::max(rect1.x, rect2.x);
    int right = std::min(rect1.x + width1, rect2.x + width2);

    for (int y = top; y < bottom; y++)
    {
        for (int x = left; x < right; x++)
        {
            if (PixelIsSolid(texture1, x - rect1.x, y - rect1.y) && PixelIsSolid(texture2, x - rect2.x, y - rect2.y))
            {
                return true;
            }
        }
    }
    return false;
}

bool CollisionSystem::PixelIsSolid(SDL_Texture* texture, int x, int y)
{
    Uint32 pixel;
    Uint32 pixels[1];
    SDL_Rect r = { x, y, 1, 1 };

    SDL_RenderReadPixels(m_renderer, &r, SDL_PIXELFORMAT_RGBA8888, pixels, sizeof(Uint32));
    pixel = pixels[0];

    SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    Uint8 red, green, blue, alpha;
    SDL_GetRGBA(pixel, format, &red, &green, &blue, &alpha);
    SDL_FreeFormat(format);

    return alpha > 200;
}