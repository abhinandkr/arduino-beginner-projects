// https://roboticsbackend.com/arduino-push-button-tutorial/

#ifndef HELLOWORLD_BUTTONPRINT_H
#define HELLOWORLD_BUTTONPRINT_H

#include <Arduino.h>
#include <pins_arduino.h>
#include "Program.h"

class ButtonPrint: public Program {
public:
    void setup() {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT_PULLUP);
    }
    void loop() {
        int buttonState = digitalRead(BUTTON_PIN);
        if (buttonState == LOW) {
            Serial.println("Button is pressed");
        } else {
            Serial.println("Button is not pressed");
        }
        delay(100);
    }
private:
    const int BUTTON_PIN = 4;
};

#endif //HELLOWORLD_BUTTONPRINT_H
