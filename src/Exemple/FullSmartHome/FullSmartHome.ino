#include <SmartHome.h>
#include <TemperatureSensor.h>
#include <Relay.h>
#include <LedUI.h>

SmartHomeLib home;
TemperatureSensor temp(34);
Relay relay(26);
LedUI led(2);

void setup() {
    Serial.begin(115200);
    home.begin();
}

void loop() {
    home.update();

    float t = temp.read();
    Serial.println(t);

    if (t > 30) relay.on();
    else relay.off();

    led.blink(500);
}