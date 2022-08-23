// https://www.instructables.com/How-to-use-Potentiometer-Arduino-Tutorial/

#ifndef HELLOWORLD_LEDPOTENTIOMETER_H
#define HELLOWORLD_LEDPOTENTIOMETER_H

#include <pins_arduino.h>
#include <Arduino.h>
#include "Program.h"

class LEDPotentiometer : public Program {
public:
    void setup() {
        pinMode(ledPin, OUTPUT);
        pinMode(potPin, INPUT);
    }

    void loop() {
        value = analogRead(potPin);
        value = map(value, 0, 1023, 0, 255);
        analogWrite(ledPin, value);
        delay(100);
    }

private:
    const int ledPin = 10;  //pin 9 has PWM funtion
    const int potPin = A0; //pin A0 to read analog input
    int value;
};


#endif //HELLOWORLD_LEDPOTENTIOMETER_H
