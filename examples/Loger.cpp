#include "Logger.h"

void Logger::info(const String& msg) {
    Serial.println("[INFO] " + msg);
}

void Logger::error(const String& msg) {
    Serial.println("[ERROR] " + msg);
}