  #include <Arduino.h>
  #include <Car.h>
  #include <Motor.h>
  #include <Arm.h>
  #include <Radio.h>
  #include <ServoJoint.h>
  #include "constants.h"


  Motor motors[NUM_OF_MOTORS] = {Motor(2,3), Motor(4,5), 
                                Motor(8,9), Motor(6, 7)};
  Car car{motors, NUM_OF_MOTORS};

  //Please initialize from shoulder downwards
  ServoJoint servos[NUM_OF_SERVOS] = {ServoJoint(SF3218MG), ServoJoint(SF3218MG)};
  Arm arm(servos, NUM_OF_SERVOS, BICEP_LENGTH, FOREARM_LENGTH);

  Radio radio;
  float controllerData[16];

  void printControllerData(bool success);
  long unsigned lastPrint = 0;

  void setup() {
    Serial.begin(115200);
    Serial.println("Startup");

    car.init();
    arm.init();
    radio.init();
  }

  void loop() {
    bool success = radio.update(controllerData);
    car.move(controllerData[0], controllerData[1], controllerData[3]);

    //so far i ac don't know what channels we'll be using soooo...
    arm.move({controllerData[2], controllerData[4]});
    printControllerData(success);

  }

void printControllerData(bool success){
  if(success && millis() - lastPrint > 100){
    lastPrint = millis();
    for(int i = 0; i < NUMBER_OF_RECEIVER_CHANNELS; i++){
      Serial.print(controllerData[i]);
      Serial.print('\t');
    }
    Serial.println();
  }
}