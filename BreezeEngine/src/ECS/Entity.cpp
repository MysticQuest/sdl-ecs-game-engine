#include "Entity.h"

Entity max_entity = 0;

std::size_t create_entity()
{
    static std::size_t entities = 0;
    ++entities;
    max_entity = entities;
    return entities;
}