//#include "Entity.h"
//#include <iostream>
//
//Entity::Entity(Transform transform, int width, int height, Vector2f velocity, SDL_Texture* texture, SDL_RendererFlip flip)
//	:m_transform(transform), m_width(width), m_height(height), m_velocity(velocity), m_texture(texture), m_flip(flip)
//{
//	m_sdlRect.x = 0;
//	m_sdlRect.y = 0;
//	m_sdlRect.w = m_width;
//	m_sdlRect.h = m_height;
// }
//
//SDL_Texture* Entity::GetTexture() const
//{
//	return m_texture;
//}
//
//SDL_Rect Entity::GetRect() const
//{
//	return m_sdlRect;
//}
//
//void Entity::Update(float deltaTime)
//{
//	m_transform.Translate(m_velocity * (deltaTime / 1000));
//	m_sdlRect.x += m_transform.X;
//	m_sdlRect.y += m_transform.Y;
//	std::cout << m_transform.X << std::endl;
//	m_sdlRect.x -= m_transform.X;
//	m_sdlRect.y -= m_transform.Y;
//}