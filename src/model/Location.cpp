#include "Location.h"

Location::Location() {
    zone = "";
    perimeter = "";
    active = false;
}

void Location::enter(const String& userId, EventBus& bus) {
    Event e;
    e.type = "location.entered";
    e.source = userId;
    e.value = 0;
    bus.emit(e);
}

void Location::exit(const String& userId, EventBus& bus) {
    Event e;
    e.type = "location.exited";
    e.source = userId;
    e.value = 0;
    bus.emit(e);
}

void Location::activateZone(EventBus& bus) {
    active = true;
    Event e;
    e.type = "location.zone_active";
    e.source = zone;
    e.value = 1;
    bus.emit(e);
}

void Location::deactivateZone(EventBus& bus) {
    active = false;
    Event e;
    e.type = "location.zone_inactive";
    e.source = zone;
    e.value = 0;
    bus.emit(e);
}

void Location::perimeterBreach(EventBus& bus) {
    Event e;
    e.type = "location.perimeter_breach";
    e.source = perimeter;
    e.value = -1;
    bus.emit(e);
}