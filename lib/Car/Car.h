#pragma once

#include <Arduino.h>
#include "Motor.h"
#include "constants.h"

class Car {
  private:
    Motor* _motors;
    int _num_motors;

  public: 
    Car(Motor* motors, int num_motors);
    void init();

    // Low-level omni kinematics / vector move (vx, vy, omega)
    void move(int vx, int vy, int omega);
    void setMotor(Motor& m, int speed);
    void normalize(int* speeds);

    // Differential drive continuous primitives
    // (Tailored for hybrid chassis: 2 front Mecanum wheels + 2 rear standard wheels)
    void drive(int leftSpeed, int rightSpeed);
    void forward(int speed);
    void backward(int speed);
    void stop();

    // Pivot turns (swing turns around one stationary side/wheel)
    void pivotTurnLeft(int speed);
    void pivotTurnRight(int speed);
    void pivotTurnLeftReverse(int speed);
    void pivotTurnRightReverse(int speed);

    // Point turns (zero-radius in-place rotation using counter-rotating sides)
    // Front Mecanum rollers freely relieve lateral scrub as the robot rotates.
    void pointTurnLeft(int speed);
    void pointTurnRight(int speed);
    void spinLeft(int speed)  { pointTurnLeft(speed); }
    void spinRight(int speed) { pointTurnRight(speed); }
    void turnLeft(int speed)  { pointTurnLeft(speed); }
    void turnRight(int speed) { pointTurnRight(speed); }

    // Timed autonomous action primitives (executes motion, delays durationMs, then stops)
    void drive(int leftSpeed, int rightSpeed, unsigned long durationMs);
    void forward(int speed, unsigned long durationMs);
    void backward(int speed, unsigned long durationMs);
    void pause(unsigned long durationMs);

    void pivotTurnLeft(int speed, unsigned long durationMs);
    void pivotTurnRight(int speed, unsigned long durationMs);
    void pivotTurnLeftReverse(int speed, unsigned long durationMs);
    void pivotTurnRightReverse(int speed, unsigned long durationMs);

    void pointTurnLeft(int speed, unsigned long durationMs);
    void pointTurnRight(int speed, unsigned long durationMs);
    void spinLeft(int speed, unsigned long durationMs)  { pointTurnLeft(speed, durationMs); }
    void spinRight(int speed, unsigned long durationMs) { pointTurnRight(speed, durationMs); }
    void turnLeft(int speed, unsigned long durationMs)  { pointTurnLeft(speed, durationMs); }
    void turnRight(int speed, unsigned long durationMs) { pointTurnRight(speed, durationMs); }
};
