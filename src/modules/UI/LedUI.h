#pragma once
#include <Arduino.h>

class LedUI {
public:
    LedUI(uint8_t pin);
    void blink(uint16_t interval);

private:
    uint8_t _pin;
    unsigned long lastToggle = 0;
    bool state = false;
};