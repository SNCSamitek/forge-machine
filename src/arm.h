#pragma once
#include <Servo.h>

class Arm{
  public:
    Arm();
    void move(int angle);
    void start();

  private:
    const int servo_pin = 5;
    Servo myServo;
};
