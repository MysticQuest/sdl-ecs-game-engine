#include "Entity.h"

Entity::Entity(float posX, float posY, SDL_Texture* texture)
	:m_posX(posX), m_posY(posY), m_texture(texture)
{
	m_sdlRect.x = 0;
	m_sdlRect.y = 0;
	m_sdlRect.w = 32;
	m_sdlRect.h = 32;
 }