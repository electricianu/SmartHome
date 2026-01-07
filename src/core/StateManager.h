#pragma once
#include <Arduino.h>

class StateManager {
public:
    void setState(const String& state);
    String getState() const;

private:
    String currentState = "idle";
};