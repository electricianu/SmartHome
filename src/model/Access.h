#ifndef ACCESS_H
#define ACCESS_H

#include <Arduino.h>
#include "core/EventBus.h"

class Access {
public:
    Access();

    void approve(EventBus& bus, const String& reason = "");
    void deny(EventBus& bus, const String& reason = "");
    void restrict(EventBus& bus, const String& mode);
};

#endif