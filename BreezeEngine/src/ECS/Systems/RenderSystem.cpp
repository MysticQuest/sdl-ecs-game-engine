#include <SDL.h>
#include "RenderSystem.h"

RenderSystem::RenderSystem(SDL_Renderer* renderer) : m_renderer(renderer) {}

void RenderSystem::Update(ECSManager& ecs)
{
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.renderComponents.contains(e) && ecs.transformComponents.contains(e))
        {
            ecs.renderComponents[e].dstRect.x = ecs.transformComponents[e].position.X;
            ecs.renderComponents[e].dstRect.y = ecs.transformComponents[e].position.Y;
        }
    }
}
void RenderSystem::Render(ECSManager& ecs, SDL_Renderer* renderer)
{
    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.renderComponents.contains(e))
        {
            SDL_RenderCopy(
                renderer,
                ecs.renderComponents[e].texture,
                &ecs.renderComponents[e].srcRect,
                &ecs.renderComponents[e].dstRect
            );
        }
    }
}

