#pragma once
#include "ServoJoint.h"

const int NUM_OF_MOTORS = 4;
enum MotorIndex {LU, RU, LD, RD};

enum MovesIndex {VX, VY, ROT};
const int NUMBER_OF_RECEIVER_CHANNELS = 16;

const float FOREARM_LENGTH = 10.0f;
const float BICEP_LENGTH = 10.0f;
enum{shoulderAngle, elbowAngle};

const int SERVO_FREQ = 50;
const int NUM_OF_SERVOS = 2;
constexpr ServoSpec SF3218MG   = {500, 2400, 270, 300};

