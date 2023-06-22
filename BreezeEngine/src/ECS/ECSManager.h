#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Components/TransformComponent.h"
#include "Components/MotionComponent.h"
#include "Components/RenderComponent.h"

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

    std::unordered_map<Entity, TransformComponent> transformComponents;
    std::unordered_map<Entity, MotionComponent> motionComponents;
    std::unordered_map<Entity, RenderComponent> renderComponents;

private:

};
