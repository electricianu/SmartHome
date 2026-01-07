#include "EventBus.h"

EventBus::EventBus() {}

void EventBus::emit(const Event& e) {
    for (auto &cb : _subscribers) {
        cb(e);
    }
}

void EventBus::on(std::function<void(Event)> callback) {
    _subscribers.push_back(callback);
}