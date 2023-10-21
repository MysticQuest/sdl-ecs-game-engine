#pragma once
#include <unordered_map>
#include <vector>
#include <functional>

enum class EventType {
};

using Callback = std::function<void(int)>;  // entity ID as parameter

class EventManager {
public:
    static void Subscribe(EventType eventType, Callback callback);
    static void Emit(EventType eventType, int entityId);

private:
    static std::unordered_map<EventType, std::vector<Callback>> subscribers;
};
