#pragma once

#include <SDL.h>
#include "IEntity.h"
#include "MyMath.h"

class Entity : public IEntity
{
public:
	Entity(Transform* transform, int width, int height, SDL_Texture* texture, SDL_RendererFlip flip = SDL_FLIP_NONE);
	const Transform& GetPos() const { return m_transform; }
	SDL_Texture* GetTexture() const;
	SDL_Rect GetRect() const;
	bool needsUpdate;

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

private:
	Transform m_transform;
	int m_width, m_height;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
	SDL_RendererFlip m_flip;
};
