#include <Arduino.h>
#include <Car.h>
#include <Motor.h>
#include <Arm.h>
#include <Radio.h>
#include <SoftwareSerial.h>
#include "constants.h"

Motor motors[NUM_OF_MOTORS] = {Motor(5,4), Motor(9,8), 
                              Motor(11,12), Motor(16, 17)};

Car car{motors, NUM_OF_MOTORS};
Arm arm;
Radio radio;
int moves[3] = {0,0,0};

void setup() {
  Serial.begin(9600);
  Serial.println("Startup");

  car.init();
  if(!arm.init()) Serial.println("Arm initializaiton has failed");
  radio.init();
}

void loop() {
  //Serial.println("Driving forward...");

  arm.setJointAngles(3, 5);

  radio.readCommands(moves, 3);
  Serial.println(moves[VX]);
  Serial.println(moves[VY]);
  Serial.println(moves[ROT]);

  //cars move takes (vx, vy and rotation)
  car.move(moves[VX],moves[VY],moves[ROT]);
  delay(1000);
}
