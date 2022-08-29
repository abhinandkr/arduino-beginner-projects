#include <Arduino.h>
#include "Program.h"
#include "LedBlink.h"
#include "LEDPotentiometer.h"
#include "ButtonPrint.h"

ButtonPollDebounce proc;
Program* program = &proc;
void setup() {
    program -> setup();
}

void loop() {
    program -> loop();
}