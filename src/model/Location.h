#ifndef LOCATION_H
#define LOCATION_H

#include <Arduino.h>
#include "core/EventBus.h"

class Location {
public:
    String zone;
    String perimeter;
    bool active;

    Location();

    void enter(const String& userId, EventBus& bus);
    void exit(const String& userId, EventBus& bus);
    void activateZone(EventBus& bus);
    void deactivateZone(EventBus& bus);
    void perimeterBreach(EventBus& bus);
};

#endif