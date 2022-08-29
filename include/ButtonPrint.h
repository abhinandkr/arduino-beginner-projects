// https://roboticsbackend.com/arduino-push-button-tutorial/

#ifndef HELLOWORLD_BUTTONPRINT_H
#define HELLOWORLD_BUTTONPRINT_H

#include <Arduino.h>
#include <pins_arduino.h>
#include "Program.h"

class ButtonPullUp : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT_PULLUP);
    }

    void loop() override {
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

class ButtonPullUpResistor : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT);
    }

    void loop() override {
        byte buttonState = digitalRead(BUTTON_PIN);

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

class ButtonPullDownResistor : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT);
    }

    void loop() override {
        byte buttonState = digitalRead(BUTTON_PIN);

        if (buttonState == HIGH) {
            Serial.println("Button is pressed");
        } else {
            Serial.println("Button is not pressed");
        }
        delay(100);
    }

private:
    const int BUTTON_PIN = 4;
};

class ButtonInterrupt : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT);
        attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonReleasedInterrupt, FALLING);
    }

    void loop() override {
        if (buttonReleased) {
            buttonReleased = false;
            Serial.println("Button released");
        }
    }

private:
    const int BUTTON_PIN = 3;
    static volatile byte buttonReleased;

    static void buttonReleasedInterrupt() {
        buttonReleased = true;
    }
};

volatile byte ButtonInterrupt::buttonReleased = false;

class ButtonPoll : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT);
    }

    void loop() override {
        byte buttonState = digitalRead(BUTTON_PIN);
        if (buttonState != lastButtonState) {
            lastButtonState = buttonState;
            if (buttonState == LOW) {
                Serial.println("Button released");
            }
        }
    }

private:
    const int BUTTON_PIN = 3;
    byte lastButtonState = LOW;
};

class ButtonPollDebounce : public Program {
public:
    void setup() override {
        Serial.begin(9600);
        pinMode(BUTTON_PIN, INPUT);
    }

    void loop() override {
        if (millis() - lastTimeButtonStateChanged > debounceDuration) {
            byte buttonState = digitalRead(BUTTON_PIN);
            if (buttonState != lastButtonState) {
                lastTimeButtonStateChanged = millis();
                lastButtonState = buttonState;
                if (buttonState == LOW) {
                    Serial.println("Button released");
                }
            }
        }
    }

private:
    const int BUTTON_PIN = 3;
    byte lastButtonState = LOW;
    unsigned long debounceDuration = 50; // millis
    unsigned long lastTimeButtonStateChanged = 0;

};

#endif //HELLOWORLD_BUTTONPRINT_H
