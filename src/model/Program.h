#ifndef PROGRAM_H
#define PROGRAM_H

#include <Arduino.h>
#include "core/EventBus.h"

class Program {
public:
    Program();

    void check(EventBus& bus); // pentru viitor: bazat pe timp
};

#endif