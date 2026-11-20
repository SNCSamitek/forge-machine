#include "HardwareSerial.h"
#include "constants.h"
#include <Arduino.h>
#include <Arm.h>
#include <Car.h>
#include <Motor.h>
#include <Radio.h>
#include <ServoJoint.h>

Motor left_up = Motor(13, 12);
Motor right_up = Motor(14, 27);
Motor left_down = Motor(26, 25);
Motor right_down = Motor(33, 32);

Motor motors[NUM_OF_MOTORS] = {left_up, right_up, left_down, right_down,};

Car car{motors, NUM_OF_MOTORS};

constexpr ServoSpec SF3218MG = {500, 2400, 270, 300};

// Please initialize from shoulder downwards
ServoJoint servos[NUM_OF_SERVOS] = {ServoJoint(SF3218MG), ServoJoint(SF3218MG)};
Arm arm(servos, NUM_OF_SERVOS, BICEP_LENGTH, FOREARM_LENGTH);

// Radio radio{&Serial, 0, 0, true};
float controllerData[16];

void printControllerData(bool success);
long unsigned lastPrint = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Startup");

    // car.init();
    left_up.begin();
    // arm.init();
    // radio.init();
}

void loop() {
    left_up.test(100.0f);
    // car.test();

    // bool success = radio.update(controllerData);
    // if (!success) {
    //     return;
    // }
    // car.move(controllerData[0], controllerData[1], controllerData[3]);

    // so far i ac don't know what channels we'll be using soooo...
    // arm.move({controllerData[2], controllerData[4]});
    // printControllerData(success);
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
