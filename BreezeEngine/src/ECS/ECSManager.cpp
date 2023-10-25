#include "ECSManager.h"
#include <type_traits>

template<IsValidComponent T>
void ECSManager::AddComponent(Entity entity, T component)
{
    auto& componentMap = GetComponentMap<T>();
    componentMap[entity] = component;
}

template<IsValidComponent T>
void ECSManager::RemoveComponent(Entity entity)
{
    auto& componentMap = GetComponentMap<T>();
    componentMap.erase(entity);
}

template<IsValidComponent T>
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

bool ECSManager::DoesEntityExist(Entity entity)
{
    return renderComponents.find(entity) != renderComponents.end();
}

template<IsValidComponent T>
std::unordered_map<Entity, T>& ECSManager::GetComponentMap()
{
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
template RenderComponent& ECSManager::GetComponent<RenderComponent>(Entity);
template TransformComponent& ECSManager::GetComponent<TransformComponent>(Entity);
template InputComponent& ECSManager::GetComponent<InputComponent>(Entity);
template CollisionComponent& ECSManager::GetComponent<CollisionComponent>(Entity);
template void ECSManager::RemoveComponent<RenderComponent>(Entity);
template void ECSManager::RemoveComponent<TransformComponent>(Entity);
template void ECSManager::RemoveComponent<InputComponent>(Entity);
template void ECSManager::RemoveComponent<CollisionComponent>(Entity);
