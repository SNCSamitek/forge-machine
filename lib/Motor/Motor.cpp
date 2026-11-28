#include "Arduino.h"
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

void Motor::forward(float speed) {
    constrain(speed, 0.0, 100.0);
    int mapped = (int) map(speed, 0.0, 100.0f, 0.0f, 255.0f);
    this->forward(mapped);
}

void Motor::backward(int speed) {
    digitalWrite(_in1Pin, LOW);
    analogWrite(_in2Pin, constrain(speed, 0, 255));
}

void Motor::backward(float speed) {
    constrain(speed, 0.0, 100.0);
    int mapped = map(speed, 0.0, 100.0, 0, 255);
    this->backward(mapped);
}

void Motor::stop() {
    digitalWrite(_in1Pin, LOW);
    digitalWrite(_in2Pin, LOW);
}

void Motor::brake() {
    digitalWrite(_in1Pin, HIGH);
    digitalWrite(_in2Pin, HIGH);
}

void Motor::test(int speed) {
    this->forward(speed);
    delay(1000);
    this->stop();
    delay(1000);
    this->backward(speed);
    delay(1000);
    this->stop();
}

void Motor::test(float speed) {
    this->forward(speed);
    delay(1000);
    this->stop();
    delay(1000);
    this->backward(speed);
    delay(1000);
    this->stop();
    delay(1000);
}
