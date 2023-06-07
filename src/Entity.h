#pragma once

#include <SDL.h>

class Entity
{
public:
	Entity(int posX, int posY, SDL_Texture* texture);
	int GetPosX() const;
	int GetPosY() const;
	SDL_Texture* GetTexture() const;
	SDL_Rect GetRect() const;
private:
	int m_posX, m_posY;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
};
