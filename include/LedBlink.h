// https://docs.arduino.cc/built-in-examples/basics/Blink

#include <Arduino.h>
#include "Program.h"

class LedBlink: public Program {
public:
    void setup() {
        pinMode(ledPin, OUTPUT);
    }

    void loop() {
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        delay(1000);
    }

private:
    const int ledPin = 8;
};


