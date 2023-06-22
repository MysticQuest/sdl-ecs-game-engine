#pragma once

#include <SDL.h>

struct RenderComponent
{
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    SDL_Texture* texture;
};