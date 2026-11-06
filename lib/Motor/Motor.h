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
    void forward(float speed); // 0-100
    void backward(int speed);
    void backward(float speed); // 0-100
    void stop();
    void brake();
    void test(int speed);
};
