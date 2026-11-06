#pragma once

#include "Motor.h"
#include "constants.h"

class Car {
  private:
    Motor* _motors;
    int _num_motors;
    void normalize(float* speeds, int num_speeds);
    void normalize(float speed);

  public:
    Car(Motor* motors, int num_motors);
    void init();
    void move(float vx, float vy, float omega);
    void setMotor(Motor& m, float speed);
    void test();
};
