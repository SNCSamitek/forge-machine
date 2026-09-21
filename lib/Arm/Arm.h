#pragma once
#include <Adafruit_PWMServoDriver.h>

// a two-joint arm
class Arm {
public:
  bool init();
  int setJointAngles(int, int);

private:
  void writeAngle(int, int);

  Adafruit_PWMServoDriver driver;
  // pin for both arms
  const int ch1 = 0, ch2 = 3;
  // link lengths
  const double ll1 = 0.35, ll2 = 0.35;
  // pulse needed for a certain degree
  const int usmin = 600, usmax = 2400;
  // current arm angles (in degrees)
  // current arm angles (in degrees)
};
};
