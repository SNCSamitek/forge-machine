#pragma once
#include "ServoJoint.h"
#include "vector.h"

class Arm {

private:
  ServoJoint* servos;
  int num_servos;
  float* angles;
  float bicepLength, forearmLength;

public:
  Arm(ServoJoint*, int, float, float);

  void init();
  bool move(vector);
  void writeAngles();
};
