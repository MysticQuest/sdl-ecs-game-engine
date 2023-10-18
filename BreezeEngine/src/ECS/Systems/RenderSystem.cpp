#include <SDL.h>
#include "RenderSystem.h"

RenderSystem::RenderSystem(SDL_Renderer* renderer) : m_renderer(renderer) {}

void RenderSystem::Update(ECSManager& ecs)
{
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.renderComponents.contains(e) && ecs.transformComponents.contains(e))
        {
            ecs.renderComponents[e].dstRect.x = static_cast<int>(ecs.transformComponents[e].position.X);
            ecs.renderComponents[e].dstRect.y = static_cast<int>(ecs.transformComponents[e].position.Y);
        }
    }
}
void RenderSystem::Render(ECSManager& ecs, SDL_Renderer* renderer)
{
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.renderComponents.contains(e))
        {
            SDL_Rect scaledDstRect = ecs.renderComponents[e].dstRect;

            scaledDstRect.w = static_cast<int>(scaledDstRect.w * ecs.transformComponents[e].scale.X);
            scaledDstRect.h = static_cast<int>(scaledDstRect.h * ecs.transformComponents[e].scale.Y);

            double angle = static_cast<double>(ecs.transformComponents[e].rotation); // Now rotation is a single value representing the angle
            SDL_Point center = { ecs.renderComponents[e].dstRect.w / 2, ecs.renderComponents[e].dstRect.h / 2 };
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
        }
    }
}

