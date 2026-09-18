#if 0
#include "arm.h"

Arm arm;
int angle = 0;

void setup(){
  arm.start();
}

void loop(){
  angle += 90;
  angle = angle%181;
  arm.move(angle);
  delay(1000);
}

#endif

#include "Motor.h"
#include <Arduino.h>

// Left Motor:  IN1 -> Pin 3,  IN2 -> Pin 5
// Right Motor: IN3 -> Pin 10, IN4 -> Pin 11
Motor leftMotor(3, 5);
Motor rightMotor(10, 11);

void driveForward(int speed) {
  leftMotor.forward(speed);
  rightMotor.forward(speed);
}

void driveBackward(int speed) {
  leftMotor.backward(speed);
  rightMotor.backward(speed);
}

void turnLeft(int speed) {
  leftMotor.backward(speed);
  rightMotor.forward(speed);
}

void turnRight(int speed) {
  leftMotor.forward(speed);
  rightMotor.backward(speed);
}

void stopRobot() {
  leftMotor.stop();
  rightMotor.stop();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Motor Test Initialized");

  leftMotor.begin();
  rightMotor.begin();
}

void loop() {
  Serial.println("Driving forward...");
  driveForward(180);
  delay(2000);

  Serial.println("Turning right...");
  turnRight(180);
  delay(1000);

  Serial.println("Driving backward...");
  driveBackward(160);
  delay(1500);

  Serial.println("Stopping...");
  stopRobot();
  delay(3000);
}