#include "Arm.h"
#include <Arduino.h>
#include <Wire.h>

bool Arm::init() {
  Wire.setWireTimeout(25000, true);

  if (!driver.begin()) {
    return false;
  }

  driver.setPWMFreq(60.f);
  return true;
}

void Arm::writeAngle(int channel, int degrees) {
  int pulseMicros = map(degrees, 0, 180, usmin, usmax);
  driver.writeMicroseconds(channel, pulseMicros);
}

int Arm::setJointAngles(int x, int y) {
  float distanceToTarget = x * x + y * y;

  if ((ll1 + ll2) < distanceToTarget ||
      abs(ll1 - ll2) > distanceToTarget) {
    Serial.println("the crane arm cannot get to that target");
    return 0;
  }

  double theta2 =
      acos((x * x + y * y - ll1 * ll1 - ll2 * ll2 / 2 * (ll1 * ll2)));
  double theta1 =
      atan2(y, x) - atan2((ll2 * sin(ll2)), (ll1 + (ll2 * cos(ll2))));
  angle1 = constrain(theta1 * (M_PI / 180), 0, 180);
  angle2 = constrain(theta2 * (M_PI / 180), 0, 180);

  writeAngle(ch1, angle1);
  writeAngle(ch2, angle2);

  Serial.println("angle set");

  return 1;
}
