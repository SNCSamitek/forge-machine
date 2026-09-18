#include "Motor.h"

Motor::Motor(int in1Pin, int in2Pin) : _in1Pin(in1Pin), _in2Pin(in2Pin) {}

void Motor::begin() {
  pinMode(_in1Pin, OUTPUT);
  pinMode(_in2Pin, OUTPUT);
  stop();
}

void Motor::forward(int speed) {
  analogWrite(_in1Pin, constrain(speed, 0, 255));
  analogWrite(_in2Pin, 0);
}

void Motor::backward(int speed) {
  analogWrite(_in1Pin, 0);
  analogWrite(_in2Pin, constrain(speed, 0, 255));
}

void Motor::stop() {
  analogWrite(_in1Pin, 0);
  analogWrite(_in2Pin, 0);
}