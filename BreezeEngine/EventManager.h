#pragma once
#include <unordered_map>
#include <functional>
#include <vector>

class EventManager {
public:
    enum class EventType {
        TransformChanged,
    };

    using EventCallback = std::function<void(int)>;

    static void Emit(EventType type, int entityId);
    static void Subscribe(EventType type, EventCallback callback);

private:
    static std::unordered_map<EventType, std::vector<EventCallback>> m_subscribers;
};
