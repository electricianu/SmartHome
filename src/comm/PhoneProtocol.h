#ifndef PHONEPROTOCOL_H
#define PHONEPROTOCOL_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "core/EventBus.h"
#include "SerialComm.h"

class PhoneProtocol {
public:
    PhoneProtocol(EventBus& bus, SerialComm& comm);

    void begin();
    void loop();              // citește mesaje de la telefon
    void sendEvent(const Event& e); // trimite evenimente spre telefon

private:
    EventBus& _bus;
    SerialComm& _comm;
};

#endif