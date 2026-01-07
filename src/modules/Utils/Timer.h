#pragma once
#include <Arduino.h>

class Timer {
public:
    Timer(uint32_t interval);
    bool elapsed();

private:
    uint32_t _interval;
    uint32_t _last = 0;
};