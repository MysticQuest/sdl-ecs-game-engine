#pragma once

#include <SDL.h>
#include "ECS/ECSManager.h"
#include "ECS/Components/RenderComponent.h"
#include "ECS/Components/TransformComponent.h"

class RenderSystem
{
public:
    RenderSystem(SDL_Renderer* renderer);
    void Update(ECSManager& ecsManager);
    void Render(ECSManager& ecsManager, SDL_Renderer* renderer);

private:
    SDL_Renderer* m_renderer;
};
