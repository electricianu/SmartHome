#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t pin) : _pin(pin) {}

float TemperatureSensor::read() {
    return analogRead(_pin) * (3.3 / 4095.0) * 100.0;
}