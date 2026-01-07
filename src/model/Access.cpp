#include "Access.h"

Access::Access() {}

void Access::approve(EventBus& bus, const String& reason) {
    Event e;
    e.type = "access.approved";
    e.source = reason;
    e.value = 1;
    bus.emit(e);
}

void Access::deny(EventBus& bus, const String& reason) {
    Event e;
    e.type = "access.denied";
    e.source = reason;
    e.value = 0;
    bus.emit(e);
}

void Access::restrict(EventBus& bus, const String& mode) {
    Event e;
    e.type = "access.restricted";
    e.source = mode;
    e.value = 0;
    bus.emit(e);
}