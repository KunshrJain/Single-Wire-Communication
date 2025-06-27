#include <Arduino.h>
#include "comms.h"

Single_Wire_Comms SWC;

void setup() {
  SWC.initialize(23, 2, 115200);
}

void loop() {
  SWC.start();
  delay(500);
}