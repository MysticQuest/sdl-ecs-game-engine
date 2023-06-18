#pragma once

#include "Entity.h"

class ShapedEntity : public Entity
{
public:
    ShapedEntity(Vector2f pos, Vector2 size, SDL_Color color)
        : Entity(pos, size), m_color(color)
    {
    }

    const SDL_Color& GetColor() const { return m_color; }

private:
    SDL_Color m_color;
};
