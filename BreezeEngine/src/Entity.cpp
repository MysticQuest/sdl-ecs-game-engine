#include "Entity.h"

Entity::Entity(Transform* transform, int width, int height, SDL_Texture* texture, SDL_RendererFlip flip)
	:m_transform(transform), m_width(width), m_height(height), m_texture(texture), m_flip(flip)
{
	m_sdlRect.x = 0;
	m_sdlRect.y = 0;
	m_sdlRect.w = m_width;
	m_sdlRect.h = m_height;
 }

SDL_Texture* Entity::GetTexture() const
{
	return m_texture;
}

SDL_Rect Entity::GetRect() const
{
	return m_sdlRect;
}