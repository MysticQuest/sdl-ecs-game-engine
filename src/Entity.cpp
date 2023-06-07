#include "Entity.h"

Entity::Entity(int posX, int posY, SDL_Texture* texture)
	:m_posX(posX), m_posY(posY), m_texture(texture)
{
	m_sdlRect.x = 0;
	m_sdlRect.y = 0;
	m_sdlRect.w = 32;
	m_sdlRect.h = 32;
 }

int Entity::GetPosX() const
{
	return m_posX;
}

int Entity::GetPosY() const
{
	return m_posY;
}

SDL_Texture* Entity::GetTexture() const
{
	return m_texture;
}

SDL_Rect Entity::GetRect() const
{
	return m_sdlRect;
}