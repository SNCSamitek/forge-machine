#include "arm.h"
#include <Arduino.h>
#include <Car.h>
#include <Motor.h>
#include "constants.h"

Motor motors[NUM_OF_MOTORS] = {Motor(5,4), Motor(9,8), 
                              Motor(11,12), Motor(16, 17)};

Car car{motors, NUM_OF_MOTORS};
Arm arm;
double t;

void setup() {
  Serial.begin(9600);
  Serial.println("Startup");

  car.init();
  if(arm.init()) {
    Serial.println("Initialized arm");
  } else {
    Serial.println("Arm failed to initialize");
  }
}

void loop() {
  Serial.println("Driving forward...");

  arm.setJointAngles(3, 5);
  
  //cars move takes (vx, vy and rotation)
  car.move(200,0,0);
  delay(1000);
}
