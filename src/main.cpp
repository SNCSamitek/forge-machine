#include "arm.h"
#include <Arduino.h>

Arm arm;
int angle = 0;

void setup(){
  arm.start();
}

void loop(){
  angle += 90;
  angle = angle%181;
  arm.move(angle);
  delay(1000);
}
