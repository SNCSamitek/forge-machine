#pragma once
#include <Adafruit_PWMServoDriver.h>
#include "vector.h"

// a two-joint arm
class Arm {

private:
  Adafruit_PWMServoDriver driver;
  int pins[2];
  float bicepLength, forearmLength;
  float shoulderAngle, elbowAngle;

public:
  Arm(int, int, float, float);

  bool init();
  bool setJointAngles(vector);
  void writeAngle(int, int);
};
