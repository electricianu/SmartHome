#include "Health.h"

Health::Health() {}

void Health::reminder(EventBus& bus, const char* type) {
    Event e;
    e.type = "health.reminder";
    e.source = type;
    e.value = 0;
    bus.emit(e);
}