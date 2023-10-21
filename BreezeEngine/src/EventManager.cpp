#include "EventManager.h"

std::unordered_map<EventType, std::vector<Callback>> EventManager::subscribers;

void EventManager::Subscribe(EventType eventType, Callback callback) {
    subscribers[eventType].push_back(callback);
}

void EventManager::Emit(EventType eventType, int entityId) {
    if (subscribers.find(eventType) != subscribers.end()) {
        for (const auto& callback : subscribers[eventType]) {
            callback(entityId);
        }
    }
}