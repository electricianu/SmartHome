#include "LedUI.h"

LedUI::LedUI(uint8_t pin) : _pin(pin) {
    pinMode(_pin, OUTPUT);
}

void LedUI::blink(uint16_t interval) {
    if (millis() - lastToggle >= interval) {
        state = !state;
        digitalWrite(_pin, state);
        lastToggle = millis();
    }
}