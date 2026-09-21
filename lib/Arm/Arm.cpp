#include "arm.h"

Arm::Arm(){}

void Arm::start(){
  _myServo.attach(this->servo_pin);
  _myServo.write(0);
}

void Arm::move(int angle){
  _myServo.write(angle);
}


