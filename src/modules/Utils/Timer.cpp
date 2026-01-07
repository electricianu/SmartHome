#include "Timer.h"

Timer::Timer(uint32_t interval) : _interval(interval) {}

bool Timer::elapsed() {
    if (millis() - _last >= _interval) {
        _last = millis();
        return true;
    }
    return false;
}