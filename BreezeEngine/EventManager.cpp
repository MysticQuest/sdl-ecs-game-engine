#include "EventManager.h"

std::unordered_map<EventManager::EventType, std::vector<EventManager::EventCallback>> EventManager::m_subscribers;

void EventManager::Emit(EventType type, int entityId) {
    auto it = m_subscribers.find(type);
    if (it != m_subscribers.end()) {
        for (const auto& callback : it->second) {
            callback(entityId);
        }
    }
}

void EventManager::Subscribe(EventType type, EventCallback callback) {
    m_subscribers[type].push_back(callback);
}
