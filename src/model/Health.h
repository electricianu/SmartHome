#ifndef HEALTH_H
#define HEALTH_H

#include "core/EventBus.h"

class Health {
public:
    Health();

    void reminder(EventBus& bus, const char* type);
};

#endif