#include <SDL.h>
#include "RenderSystem.h"
#include "../../EventManager.h"

RenderSystem::RenderSystem(SDL_Renderer* renderer) : m_renderer(renderer) {}

void RenderSystem::Update(ECSManager& ecs)
{
    for (auto& [e, renderComponent] : ecs.renderComponents)
    {
        if (ecs.transformComponents.contains(e))
        {
            ecs.renderComponents[e].dstRect.x = static_cast<int>(ecs.transformComponents[e].position.X);
            ecs.renderComponents[e].dstRect.y = static_cast<int>(ecs.transformComponents[e].position.Y);
        }
    }
}
void RenderSystem::Render(ECSManager& ecs, SDL_Renderer* renderer)
{
    for (auto& [e, renderComponent] : ecs.renderComponents)
    {
        SDL_Rect scaledDstRect = ecs.renderComponents[e].dstRect;

        scaledDstRect.w = static_cast<int>(scaledDstRect.w * ecs.transformComponents[e].scale.X);
        scaledDstRect.h = static_cast<int>(scaledDstRect.h * ecs.transformComponents[e].scale.Y);

        double angle = static_cast<double>(ecs.transformComponents[e].rotation);
        SDL_Point center = { scaledDstRect.w / 2, scaledDstRect.h / 2 };
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        // Render with rotation and scaling
        SDL_RenderCopyEx(
            renderer,
            ecs.renderComponents[e].texture,
            &ecs.renderComponents[e].srcRect,
            &scaledDstRect,
            angle,
            &center,
            flip
        );

#ifdef DEBUG
        // AABB Debug
        if (ecs.collisionComponents.contains(e))
        {
            DrawAABB(renderer, ecs.collisionComponents[e].aabb);
        }
#endif
    }
}

void RenderSystem::DrawAABB(SDL_Renderer* renderer, const AABB& aabb)
{
    // Store the current draw color
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

    // Set draw color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = {
        static_cast<int>(aabb.x),
        static_cast<int>(aabb.y),
        static_cast<int>(aabb.width),
        static_cast<int>(aabb.height)
    };
    SDL_RenderDrawRect(renderer, &rect);

    // Reset to the original draw color
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}



