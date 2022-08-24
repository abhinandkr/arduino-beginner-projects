// https://create.arduino.cc/projecthub/SBR/working-with-a-potentiometer-and-an-led-55b9d5

#ifndef HELLOWORLD_LEDPOTENTIOMETER_H
#define HELLOWORLD_LEDPOTENTIOMETER_H

//#include <pins_arduino.h>
#include <Arduino.h>
#include "Program.h"

class LEDPotentiometer : public Program {
public:
    void setup() {
        Serial.begin(9600);
        pinMode(LED_PIN, OUTPUT);
        pinMode(POT_PIN, INPUT);
    }

    void loop() {
        int potValue = analogRead(POT_PIN);
//        int brightness = potValue / 4;
        int brightness = map(potValue, 0, 1023, 0, 255);
        analogWrite(LED_PIN, brightness);
        delay(100);
        Serial.println(potValue);
    }

private:
    const int LED_PIN = 9;  // pin 11 has PWM funtion
    const int POT_PIN = A5; // pin A1 to read analog input
};


#endif //HELLOWORLD_LEDPOTENTIOMETER_H
