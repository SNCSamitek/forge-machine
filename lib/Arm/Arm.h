#pragma once
#include <Arduino.h>
#include <Servo.h>

class Arm{
  public:
    Arm();
    void move(int angle);
    void start();

  private:
    const int servo_pin = 7;
    Servo _myServo;
};
