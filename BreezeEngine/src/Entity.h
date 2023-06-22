using Entity = std::size_t;
Entity max_entities = 200000;

std::size_t create_entity()
{
    static std::size_t entities = 0;
    ++entities;
    max_entities = entities;
    return entities;
}