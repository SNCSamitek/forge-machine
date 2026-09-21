#include "arm.h"
#include <Arduino.h>

Arm arm;
double t;

void setup() {
  Serial.begin(9600);
  Serial.println("Startup");

  if (arm.init()) {
    Serial.println("PCA9685 ready");
  } else {
    Serial.println("PCA9685 not detected");
  }
}

void loop() {
  arm.setJointAngles(0.1, 0);
  
  delay(1000);
}