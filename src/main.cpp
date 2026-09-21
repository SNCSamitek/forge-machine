#include <Arduino.h>
#include <Car.h>
#include <Motor.h>
#include "constants.h"

Motor motors[NUM_OF_MOTORS] = {Motor(5,4), Motor(9,8), 
                              Motor(11,12), Motor(16, 17)};

Car car{motors, NUM_OF_MOTORS};

void setup() {
  Serial.begin(9600);
  Serial.println("Motor Test Initialized");

  car.init();
}

void loop() {
  Serial.println("Driving forward...");

  //cars move takes (vx, vy and rotation)
  car.move(200,0,0);
  delay(1000);
}
