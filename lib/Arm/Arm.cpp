#include "Arm.h"
#include "constants.h"
#include <Arduino.h>
#include <Wire.h>

Arm::Arm(int p1, int p2, float bl, float fl) : pins({p1,p2}), forearmLength(fl), bicepLength(bl){}

bool Arm::init() {}

void Arm::writeAngle(int channel, int degrees) {
  
}

bool Arm::setJointAngles(vector target) {
  if(target.getHypo() > forearmLength + bicepLength ||
    target.getHypo() < fabs(forearmLength - bicepLength))
    return false;

  //LENGTHS
  float h = (float)target.getHypo();
  float l = (float)BICEP_LENGTH;
  float k = (float)FOREARM_LENGTH;

  this->shoulderAngle = degrees(target.getAngle() + acos((h*h + l*l - k*k)/(2*l*h)));
  this->elbowAngle = degrees(acos((h*h - l*l - k*k)/(2*l*k)));

  return true;
}
