#pragma once
#include <Arduino.h>

class Logger {
public:
    static void info(const String& msg);
    static void error(const String& msg);
};