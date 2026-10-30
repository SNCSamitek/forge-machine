#include "Arm.h"
#include "constants.h"
#include <Arduino.h>

Arm::Arm(ServoJoint* servos, int numOfServos, float bl, float fl) : 
servos(servos), num_servos(numOfServos), angles(new float[numOfServos]),
bicepLength(bl), forearmLength(fl) {}

void Arm::init() {
  ServoJoint::initDriver();

  for(int i = 0; i < num_servos; i++){
    servos[i].begin(135.0f);
    angles[i] = 135.0f;
  }
}

void Arm::writeAngles(){
  for(int i = 0; i < num_servos; i++)
    servos[i].update(angles[i]);
}

bool Arm::move(vector target) {
  //LENGTHS
  float h = (float)target.getHypo();
  float bl = (float)bicepLength;
  float fl = (float)forearmLength;

  if(h > bl + fl || h < fabs(fl - bl) || h < 0.001f){
    writeAngles();
    return false;
  }

  //INVERSE FORMULA FOR 2-DOF
  float a = constrain((h*h + bl*bl - fl*fl)/(2*bl*h), -1.0f, 1.0f);
  float b = constrain((h*h - bl*bl - fl*fl)/(2*bl*fl), -1.0f, 1.0f);

  this->angles[shoulderAngle] = degrees(target.getAngle() + acos(a));
  this->angles[elbowAngle] = degrees(acos(b));

  writeAngles();
  return true;
}
