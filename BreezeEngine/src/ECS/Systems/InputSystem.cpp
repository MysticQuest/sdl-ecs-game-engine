#include "ControlSchemes.h"
#include "InputSystem.h"

void InputSystem::Update(ECSManager& ecs)
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    for (int e = 1; e <= max_entity; e++)
    {
        if (ecs.transformComponents.contains(e) && ecs.inputComponents.contains(e))
        {
            auto& inputComponent = ecs.inputComponents[e];
            auto& transformComponent = ecs.transformComponents[e];

            if (inputComponent.controlScheme[ACTION_LEFT] && keys[SDL_SCANCODE_A])
            {
                transformComponent.position.X -= inputComponent.inputSensitivity;
            }
            if (inputComponent.controlScheme[ACTION_DOWN] && keys[SDL_SCANCODE_S])
            {
                transformComponent.position.Y += inputComponent.inputSensitivity;
            }
            if (inputComponent.controlScheme[ACTION_UP] && keys[SDL_SCANCODE_W])
            {
                transformComponent.position.Y -= inputComponent.inputSensitivity;
            }
            if (inputComponent.controlScheme[ACTION_RIGHT] && keys[SDL_SCANCODE_D])
            {
                transformComponent.position.X += inputComponent.inputSensitivity;
            }
        }
    }
}