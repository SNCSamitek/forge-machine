#include "Car.h"
#include "Motor.h"

Car::Car(Motor* motors, int num_motors) : _motors(motors), _num_motors(num_motors){}

void Car::init(){
  for(int i = 0; i < _num_motors; i++)
    _motors[i].begin();
}

void Car::move(int vx, int vy, int omega){
  int speeds[NUM_OF_MOTORS];

  speeds[LU] = vx - vy - omega;
  speeds[RU] = vx + vy + omega;
  speeds[LD] = vx + vy - omega;
  speeds[RD] = vx - vy + omega;

  normalize(speeds);

  for(int i = 0; i < _num_motors; i++)
    setMotor(_motors[i], speeds[i]);
}

void Car::setMotor(Motor& m, int speed){
  if(speed < 0)
    m.backward(constrain(-speed, 0, 255));
  else if(speed > 0)
    m.forward(constrain(speed, 0, 255));
  else
    m.stop();
}

void Car::normalize(int* speeds){
  int maxSpeed = 0;

  // Find max magnitude
  for(int i = 0; i < NUM_OF_MOTORS; i++){
    int mag = abs(speeds[i]);
    if(mag > maxSpeed) maxSpeed = mag;
  }
  
  // Scale down proportionally if any motor exceeds 255
  if(maxSpeed > 255){
    for(int i = 0; i < NUM_OF_MOTORS; i++){
      speeds[i] = (long)speeds[i] * 255 / maxSpeed;
    }
  }
}

// -------------------------------------------------------------
// Differential Drive Movement Primitives
// Front: Mecanum wheels (LU, RU) relieve lateral scrub during turns.
// Rear:  High-grip standard wheels (LD, RD) dictate pivot axis.
// -------------------------------------------------------------

void Car::drive(int leftSpeed, int rightSpeed){
  int speeds[NUM_OF_MOTORS];

  speeds[LU] = leftSpeed;
  speeds[LD] = leftSpeed;
  speeds[RU] = rightSpeed;
  speeds[RD] = rightSpeed;

  normalize(speeds);

  for(int i = 0; i < _num_motors; i++)
    setMotor(_motors[i], speeds[i]);
}

void Car::forward(int speed){
  drive(speed, speed);
}

void Car::backward(int speed){
  drive(-speed, -speed);
}

void Car::stop(){
  for(int i = 0; i < _num_motors; i++)
    _motors[i].stop();
}

// Pivot turns: Pivot around the stationary rear tire.
// Mecanum rollers on the opposite front wheel freely relieve lateral drag.
void Car::pivotTurnLeft(int speed){
  drive(0, speed);
}

void Car::pivotTurnRight(int speed){
  drive(speed, 0);
}

void Car::pivotTurnLeftReverse(int speed){
  drive(0, -speed);
}

void Car::pivotTurnRightReverse(int speed){
  drive(-speed, 0);
}

// Point turns: Zero-radius turn in place with counter-rotating sides.
void Car::pointTurnLeft(int speed){
  drive(-speed, speed);
}

void Car::pointTurnRight(int speed){
  drive(speed, -speed);
}

// -------------------------------------------------------------
// Timed Autonomous Action Primitives
// -------------------------------------------------------------

void Car::drive(int leftSpeed, int rightSpeed, unsigned long durationMs){
  drive(leftSpeed, rightSpeed);
  delay(durationMs);
  stop();
}

void Car::forward(int speed, unsigned long durationMs){
  forward(speed);
  delay(durationMs);
  stop();
}

void Car::backward(int speed, unsigned long durationMs){
  backward(speed);
  delay(durationMs);
  stop();
}

void Car::pause(unsigned long durationMs){
  stop();
  delay(durationMs);
}

void Car::pivotTurnLeft(int speed, unsigned long durationMs){
  pivotTurnLeft(speed);
  delay(durationMs);
  stop();
}

void Car::pivotTurnRight(int speed, unsigned long durationMs){
  pivotTurnRight(speed);
  delay(durationMs);
  stop();
}

void Car::pivotTurnLeftReverse(int speed, unsigned long durationMs){
  pivotTurnLeftReverse(speed);
  delay(durationMs);
  stop();
}

void Car::pivotTurnRightReverse(int speed, unsigned long durationMs){
  pivotTurnRightReverse(speed);
  delay(durationMs);
  stop();
}

void Car::pointTurnLeft(int speed, unsigned long durationMs){
  pointTurnLeft(speed);
  delay(durationMs);
  stop();
}

void Car::pointTurnRight(int speed, unsigned long durationMs){
  pointTurnRight(speed);
  delay(durationMs);
  stop();
}
