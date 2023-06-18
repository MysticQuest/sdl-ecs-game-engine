#pragma once

#include <SDL.h>
#include "MyMath.h"

class Entity
{
public:
	Entity(Vector2f pos, Vector2 size, SDL_Texture* texture);
	const Vector2f& GetPos() const { return m_pos; }
	SDL_Texture* GetTexture() const;
	SDL_Rect GetRect() const;
private:
	Vector2f m_pos;
	Vector2 m_size;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
};
