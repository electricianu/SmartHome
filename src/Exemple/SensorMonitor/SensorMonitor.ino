#include <TemperatureSensor.h>

TemperatureSensor temp(34);

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println(temp.read());
    delay(1000);
}