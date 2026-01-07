#include "SystemMonitor.h"

SystemMonitor::SystemMonitor(EventBus& bus)
    : _bus(bus) {}

void SystemMonitor::boot() {
    Event e;
    e.type = "system.boot";
    e.source = "system";
    e.value = 1;
    _bus.emit(e);
}

void SystemMonitor::shutdown() {
    Event e;
    e.type = "system.shutdown";
    e.source = "system";
    e.value = 0;
    _bus.emit(e);
}

void SystemMonitor::lowPower(float voltage) {
    Event e;
    e.type = "system.low_power";
    e.source = "power";
    e.value = voltage;
    _bus.emit(e);
}

void SystemMonitor::overheat(float temp) {
    Event e;
    e.type = "system.overheat";
    e.source = "internal_temp";
    e.value = temp;
    _bus.emit(e);
}