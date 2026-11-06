#include "Car.h"
#include "Arduino.h"
#include "Motor.h"
#include "constants.h"

Car::Car(Motor* motors, int num_motors) : _motors(motors), _num_motors(num_motors){}

void Car::init(){
  for(int i = 0; i < _num_motors; i++)
    _motors[i].begin();
}

void Car::move(float vx, float vy, float omega){

  float speeds[NUM_OF_MOTORS];

  speeds[LU] = vx - vy - omega;
  speeds[RU] = vx + vy + omega;
  speeds[LD] = vx + vy - omega;
  speeds[RD] = vx - vy + omega;

  // this->normalize(speeds, NUM_OF_MOTORS);

  for(int i = 0; i < _num_motors; i++)
    setMotor(_motors[i], speeds[i]);
}

void Car::setMotor(Motor& m, float speed){
  if(speed < 0)
    m.backward(-speed);
  else
    m.forward(speed);
}

void Car::normalize(float* speeds, int num_speeds){
  int maxSpeed = 0;

  //find max
  for(int i = 0; i < NUM_OF_MOTORS; i++){
    int mag = abs(speeds[i]);
    if(mag > maxSpeed) maxSpeed = mag;
  }

  //normalize
  if(maxSpeed > 255){
    for(int i = 0; i < NUM_OF_MOTORS; i++){
      speeds[i] = (long)speeds[i] * 255/maxSpeed;
    }
  }
}

void Car::test() {
    this->move(0, 100, 0);
    delay(1000);
    this->move(0, -100, 0);
    delay(1000);
    this->move(0, 0, 0);
    delay(1000);
}
