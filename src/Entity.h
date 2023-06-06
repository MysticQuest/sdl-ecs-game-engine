#pragma once

#include <SDL.h>

class Entity
{
public:
	Entity(float posX, float posY, SDL_Texture* texture);
	~Entity();
private:
	float m_posX, m_posY;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
};
