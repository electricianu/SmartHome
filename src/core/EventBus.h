#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <Arduino.h>
#include <functional>
#include <vector>

struct Event {
    String type;    // ex: "sensor.motion", "system.boot"
    String source;  // ex: "pir1", "system", "phone"
    float value;    // numeric payload generic
};

class EventBus {
public:
    EventBus();

    void emit(const Event& e);
    void on(std::function<void(Event)> callback);

private:
    std::vector<std::function<void(Event)>> _subscribers;
};

#endif