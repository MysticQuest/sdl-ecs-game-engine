#include "ECSManager.h"
#include <type_traits>

// Explicit template specialization declarations
template<>
std::unordered_map<Entity, RenderComponent>& ECSManager::GetComponentMap();
template<>
std::unordered_map<Entity, TransformComponent>& ECSManager::GetComponentMap();
template<>
std::unordered_map<Entity, InputComponent>& ECSManager::GetComponentMap();
template<>
std::unordered_map<Entity, CollisionComponent>& ECSManager::GetComponentMap();

template<typename T>
void ECSManager::AddComponent(Entity entity, T component)
{
    auto& componentMap = GetComponentMap<T>();
    componentMap[entity] = component;
}

template<typename T>
void ECSManager::RemoveComponent(Entity entity)
{
    auto& componentMap = GetComponentMap<T>();
    componentMap.erase(entity);
}

template<typename T>
T& ECSManager::GetComponent(Entity entity)
{
    return GetComponentMap<T>()[entity];
}

void ECSManager::DestroyEntity(Entity entity)
{
    RemoveComponent<RenderComponent>(entity);
    RemoveComponent<TransformComponent>(entity);
    RemoveComponent<InputComponent>(entity);
    RemoveComponent<CollisionComponent>(entity);
}

bool ECSManager::HasInputComponents() const
{
    return !inputComponents.empty();
}

template<typename T>
std::unordered_map<Entity, T>& ECSManager::GetComponentMap()
{
    static_assert(
        std::is_same<T, RenderComponent>::value ||
        std::is_same<T, TransformComponent>::value ||
        std::is_same<T, InputComponent>::value ||
        std::is_same<T, CollisionComponent>::value,
        "Invalid component type."
        );

    static std::unordered_map<Entity, T> emptyMap;
    return emptyMap;
}

// Explicit template specialization definitions
template<>
std::unordered_map<Entity, RenderComponent>& ECSManager::GetComponentMap<RenderComponent>()
{
    return renderComponents;
}

template<>
std::unordered_map<Entity, TransformComponent>& ECSManager::GetComponentMap<TransformComponent>()
{
    return transformComponents;
}

template<>
std::unordered_map<Entity, InputComponent>& ECSManager::GetComponentMap<InputComponent>()
{
    return inputComponents;
}

template<>
std::unordered_map<Entity, CollisionComponent>& ECSManager::GetComponentMap<CollisionComponent>()
{
    return collisionComponents;
}

// Explicit template instantiation
template void ECSManager::AddComponent<RenderComponent>(Entity, RenderComponent);
template void ECSManager::AddComponent<TransformComponent>(Entity, TransformComponent);
template void ECSManager::AddComponent<InputComponent>(Entity, InputComponent);
template void ECSManager::AddComponent<CollisionComponent>(Entity, CollisionComponent);
template void ECSManager::RemoveComponent<RenderComponent>(Entity);
template void ECSManager::RemoveComponent<TransformComponent>(Entity);
template void ECSManager::RemoveComponent<InputComponent>(Entity);
template void ECSManager::RemoveComponent<CollisionComponent>(Entity);
