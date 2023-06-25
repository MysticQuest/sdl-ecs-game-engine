#include "InputSystem.h"

void InputSystem::Update(ECSManager& ecs)
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.transformComponents.contains(e) && ecs.inputComponents.contains(e))
        {

            if (keys[SDL_SCANCODE_A]) { ecs.transformComponents[e].position.X -= 1.0f; }
            if (keys[SDL_SCANCODE_S]) { ecs.transformComponents[e].position.Y += 1.0f; }
            if (keys[SDL_SCANCODE_W]) { ecs.transformComponents[e].position.Y -= 1.0f; }
            if (keys[SDL_SCANCODE_D]) { ecs.transformComponents[e].position.X += 1.0f; }
        }
    }
}