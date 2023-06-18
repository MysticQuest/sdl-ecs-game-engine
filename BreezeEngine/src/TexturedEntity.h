#pragma once

#include "Entity.h"

class TexturedEntity : public Entity
{
public:
    TexturedEntity(Vector2f pos, Vector2 size, SDL_Texture* texture, SDL_Rect rect)
        : Entity(pos, size), m_texture(texture), m_rect(rect)
    {
    }

    SDL_Texture* GetTexture() const { return m_texture; }
    const SDL_Rect& GetRect() const { return m_rect; }

private:
    SDL_Texture* m_texture;
    SDL_Rect m_rect;
};