#include "StateManager.h"

void StateManager::setState(const String& state) {
    currentState = state;
}

String StateManager::getState() const {
    return currentState;
}