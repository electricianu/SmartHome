#ifndef SYSTEMMONITOR_H
#define SYSTEMMONITOR_H

#include "core/EventBus.h"

class SystemMonitor {
public:
    SystemMonitor(EventBus& bus);

    void boot();
    void shutdown();
    void lowPower(float voltage);
    void overheat(float temp);

private:
    EventBus& _bus;
};

#endif