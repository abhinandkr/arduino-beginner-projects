#include <Arduino.h>
#include "Program.h"
#include "LedBlink.h"
#include "LEDPotentiometer.h"

Program* program = new LedBlink();
void setup() {
    program -> setup();
}

void loop() {
    program -> loop();
}