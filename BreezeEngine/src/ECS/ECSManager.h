#pragma once

#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Components/RenderComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TransformComponent.h"
#include "Components/InputComponent.h"

class ECSManager
{
public:
    template<typename T>
    void AddComponent(Entity entity, T component)
    {
        static_assert(
            std::is_same<T, RenderComponent>::value ||
            std::is_same<T, TransformComponent>::value ||
            std::is_same<T, InputComponent>::value ||
            std::is_same<T, CollisionComponent>::value,
            "Invalid component type."
            );

        GetComponentMap<T>()[entity] = component;
    }

    template<typename T>
    void RemoveComponent(Entity entity)
    {
        static_assert(
            std::is_same<T, RenderComponent>::value ||
            std::is_same<T, TransformComponent>::value ||
            std::is_same<T, InputComponent>::value ||
            std::is_same<T, CollisionComponent>::value,
            "Invalid component type."
            );

        GetComponentMap<T>().erase(entity);
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        static_assert(
            std::is_same<T, RenderComponent>::value ||
            std::is_same<T, TransformComponent>::value ||
            std::is_same<T, InputComponent>::value ||
            std::is_same<T, CollisionComponent>::value,
            "Invalid component type."
            );

        return GetComponentMap<T>()[entity];
    }

    std::unordered_map<Entity, RenderComponent> renderComponents;
    std::unordered_map<Entity, TransformComponent> transformComponents;
    std::unordered_map<Entity, InputComponent> inputComponents;
    std::unordered_map<Entity, CollisionComponent> collisionComponents;

private:
    template<typename T>
    std::unordered_map<Entity, T>& GetComponentMap()
    {
        static_assert(sizeof(T) == 0, "Unsupported component type.");
    }

    template<>
    std::unordered_map<Entity, RenderComponent>& GetComponentMap<RenderComponent>()
    {
        return renderComponents;
    }

    template<>
    std::unordered_map<Entity, TransformComponent>& GetComponentMap<TransformComponent>()
    {
        return transformComponents;
    }

    template<>
    std::unordered_map<Entity, InputComponent>& GetComponentMap<InputComponent>()
    {
        return inputComponents;
    }

    template<>
    std::unordered_map<Entity, CollisionComponent>& GetComponentMap<CollisionComponent>()
    {
        return collisionComponents;
    }
};
