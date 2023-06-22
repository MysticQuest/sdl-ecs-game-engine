#pragma once

#include <SDL.h>

class Renderer
{
	SDL_Texture* GetTexture() const { return m_texture; }
	SDL_Rect GetRect() const { return m_sdlRect; }

	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
	SDL_RendererFlip m_flip = SDL_FLIP_NONE;
};