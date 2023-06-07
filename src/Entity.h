#pragma once

#include <SDL.h>
#include "MyMath.h"

class Entity
{
public:
	Entity(Vector2f m_pos, SDL_Texture* texture);
	const Vector2f& GetPos() const { return m_pos; }
	SDL_Texture* GetTexture() const;
	SDL_Rect GetRect() const;
private:
	Vector2f m_pos;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
};
