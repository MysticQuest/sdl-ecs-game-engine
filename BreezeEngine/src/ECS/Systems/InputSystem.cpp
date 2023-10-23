#include "ControlSchemes.h"
#include "InputSystem.h"

void InputSystem::Update(ECSManager& ecs)
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    for (auto& [e, inputComp] : ecs.inputComponents)
    {
        auto itTransform = ecs.transformComponents.find(e);

        if (itTransform != ecs.transformComponents.end())
        {
            auto& inputComponent = inputComp;  // You already have this from the loop
            auto& transformComponent = itTransform->second;

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
