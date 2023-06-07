#include "Entity.h"

Entity::Entity(Vector2f pos, SDL_Texture* texture)
	:m_pos(pos), m_texture(texture)
{
	m_sdlRect.x = 0;
	m_sdlRect.y = 0;
	m_sdlRect.w = 32;
	m_sdlRect.h = 32;
 }

SDL_Texture* Entity::GetTexture() const
{
	return m_texture;
}

SDL_Rect Entity::GetRect() const
{
	return m_sdlRect;
}