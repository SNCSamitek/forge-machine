#include <Motor.h>

Motor::Motor(int in1Pin, int in2Pin) : _in1Pin(in1Pin), _in2Pin(in2Pin) {}

void Motor::begin() {
  pinMode(_in1Pin, OUTPUT);
  pinMode(_in2Pin, OUTPUT);
}

void Motor::forward(int speed) {
  analogWrite(_in1Pin, constrain(speed, 0, 255));
  digitalWrite(_in2Pin, LOW);
}

void Motor::backward(int speed) {
  digitalWrite(_in1Pin, LOW);
  analogWrite(_in2Pin, constrain(speed, 0, 255));
}

void Motor::stop() {
  digitalWrite(_in1Pin, LOW);
  digitalWrite(_in2Pin, LOW);
}

void Motor::brake(){
  digitalWrite(_in1Pin, HIGH);
  digitalWrite(_in2Pin, HIGH);
}