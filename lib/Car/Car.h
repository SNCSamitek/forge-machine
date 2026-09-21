#pragma once

#include "motor.h"
#include "constants.h"

class Car {
  private:
    Motor* _motors;
    int _num_motors;
  public: 
    Car(Motor* motors, int num_motors);
    void init();
    void move(int vx, int vy, int omega);
    void setMotor(Motor& m, int speed);
    void normalize(int* speeds);
};
