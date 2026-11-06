#include "HardwareSerial.h"
#include "constants.h"
#include <Arduino.h>
#include <Arm.h>
#include <Car.h>
#include <Motor.h>
#include <Radio.h>
#include <ServoJoint.h>

Motor motors[NUM_OF_MOTORS] = {Motor(2, 3), Motor(5, 4), Motor(9, 8),
                               Motor(6, 7)};

Car car{motors, NUM_OF_MOTORS};

constexpr ServoSpec SF3218MG = {500, 2400, 270, 300};

// Please initialize from shoulder downwards
ServoJoint servos[NUM_OF_SERVOS] = {ServoJoint(SF3218MG), ServoJoint(SF3218MG)};
Arm arm(servos, NUM_OF_SERVOS, BICEP_LENGTH, FOREARM_LENGTH);

Radio radio{&Serial3};
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
    if (!success) {
        return;
    }
    car.move(controllerData[0], controllerData[1], controllerData[3]);

    // so far i ac don't know what channels we'll be using soooo...
    arm.move({controllerData[2], controllerData[4]});
    printControllerData(success);
}

void printControllerData(bool success) {
    if (success && millis() - lastPrint > 100) {
        lastPrint = millis();
        for (int i = 0; i < NUMBER_OF_RECEIVER_CHANNELS; i++) {
            Serial.print(controllerData[i]);
            Serial.print('\t');
        }
        Serial.println();
    }
}
