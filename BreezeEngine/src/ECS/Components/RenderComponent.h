#pragma once
#include <SDL.h>

struct RenderComponent
{
    SDL_Rect srcRect = { 0, 0, 32, 32 };
    SDL_Rect dstRect = { 0, 0, 32, 32 };
    SDL_Texture* texture;
};