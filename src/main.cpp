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
float controllerData[16];

void printControllerData();
long unsigned lastPrint = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Startup");

  car.init();
  if(!arm.init()) Serial.println("Arm initializaiton has failed");
  radio.init();
}

void loop() {
  //Serial.println("Driving forward...");

  //arm.setJointAngles(3, 5);

  bool success = radio.update(controllerData);

  if(success && millis() - lastPrint > 100){
    lastPrint = millis();
    printControllerData();
  }

}

void printControllerData(){
  for(int i = 0; i < NUMBER_OF_RECEIVER_CHANNELS; i++){
    Serial.print(controllerData[i]);
    Serial.print('\t');
  }
  Serial.println();
}