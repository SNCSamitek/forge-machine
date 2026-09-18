#include "arm.h"
#include <Arduino.h> 
#include <Servo.h>

Arm::Arm(){}

void Arm::start(){
  this->myServo.attach(this->servo_pin);
  myServo.write(0);
}

void Arm::move(int angle){
  this->myServo.write(angle);
}


