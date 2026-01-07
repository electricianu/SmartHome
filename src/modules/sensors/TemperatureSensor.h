#pragma once
#include <Arduino.h>

class TemperatureSensor {
public:
    TemperatureSensor(uint8_t pin);
    float read();

private:
    uint8_t _pin;
};