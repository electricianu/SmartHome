#include "PhoneProtocol.h"

PhoneProtocol::PhoneProtocol(EventBus& bus, SerialComm& comm)
    : _bus(bus), _comm(comm) {}

void PhoneProtocol::begin() {
    _comm.begin();
}

void PhoneProtocol::loop() {
    if (_comm.available()) {
        String json = _comm.readLine();
        if (json.length() == 0) return;

        DynamicJsonDocument doc(256);
        DeserializationError err = deserializeJson(doc, json);
        if (err) return;

        const char* type = doc["type"];
        const char* action = doc["payload"]["action"];

        Event e;
        e.type = "phone.command";
        e.source = action ? action : "";
        e.value = 0;
        _bus.emit(e);
    }
}

void PhoneProtocol::sendEvent(const Event& e) {
    DynamicJsonDocument doc(256);
    doc["type"] = "event";
    doc["source"] = e.source;
    JsonObject payload = doc.createNestedObject("payload");
    payload["event_type"] = e.type;
    payload["value"] = e.value;

    String out;
    serializeJson(doc, out);
    _comm.sendLine(out);
}