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
    m.backward(constrain(-speed,0,255));
  else
    m.forward(constrain(speed,0,255));
}

void Car::normalize(int* speeds){
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

