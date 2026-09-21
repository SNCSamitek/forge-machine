#pragma once
#include <Arduino.h>

class Motor {
  private:
    int _in1Pin;
    int _in2Pin;

  public:
    Motor(int in1Pin, int in2Pin);
    void begin();
    void forward(int speed);
    void backward(int speed);
    void stop();
};