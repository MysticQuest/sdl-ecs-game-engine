#pragma once

#include <unordered_map>
#include "Entity.h"
#include "Components/RenderComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TransformComponent.h"
#include "Components/InputComponent.h"

template<typename T>
concept IsValidComponent = 
std::is_same_v<T, RenderComponent> ||
std::is_same_v<T, TransformComponent> ||
std::is_same_v<T, InputComponent> ||
std::is_same_v<T, CollisionComponent>;

class ECSManager
{
public:
    template<IsValidComponent  T>
    void AddComponent(Entity entity, T component);

    template<IsValidComponent  T>
    void RemoveComponent(Entity entity);

    template<IsValidComponent  T>
    T& GetComponent(Entity entity);

    void DestroyEntity(Entity entity);

    bool HasInputComponents() const;
    bool DoesEntityExist(Entity entity);

    std::unordered_map<Entity, RenderComponent> renderComponents;
    std::unordered_map<Entity, TransformComponent> transformComponents;
    std::unordered_map<Entity, InputComponent> inputComponents;
    std::unordered_map<Entity, CollisionComponent> collisionComponents;

private:
    template<IsValidComponent T>
    std::unordered_map<Entity, T>& GetComponentMap();
};
