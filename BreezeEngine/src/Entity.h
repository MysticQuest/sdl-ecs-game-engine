#pragma once

#include <SDL.h>
#include "MyMath.h"

class Entity
{
public:
	Entity(Transform transform, int width, int height, Vector2f velocity, SDL_Texture* texture, SDL_RendererFlip flip = SDL_FLIP_NONE);
	const Transform& GetPos() const { return m_transform; }
	SDL_Texture* GetTexture() const;
	SDL_Rect GetRect() const;
	bool needsUpdate = false;

	void Update(float deltaTime);

private:
	Transform m_transform;
	int m_width, m_height;
	Vector2f m_velocity;
	SDL_Rect m_sdlRect;
	SDL_Texture* m_texture;
	SDL_RendererFlip m_flip;
};
