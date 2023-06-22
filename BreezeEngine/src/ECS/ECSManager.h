#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Components/RenderComponent.h"
#include "Components/TransformComponent.h"
#include "Components/InputComponent.h"

class ECSManager
{
public:
    Entity CreateEntity();
    void DestroyEntity(Entity entity);

    template <typename T>
    void AddComponent(Entity entity, T component);

    template <typename T>
    void RemoveComponent(Entity entity);

    template <typename T>
    T& GetComponent(Entity entity);

    std::unordered_map<Entity, RenderComponent> renderComponents;
    std::unordered_map<Entity, TransformComponent> transformComponents;
    std::unordered_map<Entity, InputComponent> inputComponents;

private:

};
