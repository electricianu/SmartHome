#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <Arduino.h>

class SerialComm {
public:
    SerialComm(HardwareSerial& serial = Serial, uint32_t baud = 115200);

    void begin();
    bool available();
    String readLine();
    void sendLine(const String& line);

private:
    HardwareSerial& _serial;
    uint32_t _baud;
    String _buffer;
};

#endif