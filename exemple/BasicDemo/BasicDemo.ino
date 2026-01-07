#include <SmartHomeLib.h>

SmartHomeLib home;

void setup() {
    Serial.begin(115200);
    home.begin();
}

void loop() {
    home.update();
}