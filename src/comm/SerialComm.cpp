#include "SerialComm.h"

SerialComm::SerialComm(HardwareSerial& serial, uint32_t baud)
    : _serial(serial), _baud(baud) {}

void SerialComm::begin() {
    _serial.begin(_baud);
}

bool SerialComm::available() {
    while (_serial.available()) {
        char c = _serial.read();

        if (c == '\n') {
            return true;
        }

        if (c != '\r') {
            _buffer += c;
        }
    }
    return false;
}

String SerialComm::readLine() {
    String line = _buffer;
    _buffer = "";
    return line;
}

void SerialComm::sendLine(const String& line) {
    _serial.println(line);
}