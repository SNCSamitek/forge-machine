#include "HardwareSerial.h"
#include "constants.h"
#include <Arduino.h>
#include <Arm.h>
#include <Claw.h>
#include <Telescope.h>
#include <Car.h>
#include <Motor.h>
#include <Radio.h>
#include <ServoJoint.h>

Motor left_up = Motor(6, 7);
Motor right_up = Motor(9, 8);
Motor left_down = Motor(10, 11);
Motor right_down = Motor(13, 12);

Motor motors[NUM_OF_MOTORS] = {left_up, right_up, left_down, right_down,};

Car car{motors, NUM_OF_MOTORS};

constexpr ServoSpec SF3218MG = {500, 2400, 270, 300};

// Please initialize shoulder first, elbow second
ServoJoint arm_servos[NUM_OF_SERVOS] = {ServoJoint(SF3218MG), ServoJoint(SF3218MG)};
Arm arm(arm_servos, NUM_OF_SERVOS, BICEP_LENGTH, FOREARM_LENGTH);

//Please initialize wrist first, fingers second
ServoJoint claw_servos[NUM_OF_SERVOS] = {ServoJoint(SF3218MG), ServoJoint(SF3218MG)};
Claw claw(claw_servos, NUM_OF_SERVOS);

int lengthTelescope = 420;
Telescope telescope{ServoJoint(SF3218MG), lengthTelescope};

#if defined (ESP32)
Radio radio{&Serial, 0, 0, true};
#else
Radio radio(&Serial3);
#endif
float controllerData[16];

void printControllerData(bool success);
long unsigned lastPrint = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Startup");
    car.init();

    ServoJoint::initDriver();
    if(!arm.init())
        Serial.println("arm failed to initialize");
    if(!claw.init())
        Serial.println("claw failed to initialize");

    radio.init();
    for(size_t i=0;i<16;i++){
        controllerData[i] = 0;
    }
}

void loop() {
    // right_up.test(100.0f);
    // left_up.test(100.0f);
    // right_down.test(100.0f);
    // left_down.test(100.0f);
    // car.test();

    bool success = radio.update(controllerData);
    // printControllerData(success);
    if (!success) {
        Serial.println("Couldn't read controller data");
        return;
    }
    car.move(controllerData[1], controllerData[0], controllerData[3]);

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
    } else {
        Serial.println("Couldn't read controller");
    }
}
