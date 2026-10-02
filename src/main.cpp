#include <Arduino.h>
#include <Car.h>
#include <Motor.h>
#include <Arm.h>
#include <Radio.h>
#include <SoftwareSerial.h>
#include "constants.h"

// Motor Pin Mapping:
// LU (Front-Left, Mecanum) : PWM=5,  DIR=4
// RU (Front-Right, Mecanum): PWM=9,  DIR=8
// LD (Rear-Left, Standard) : PWM=11, DIR=12
// RD (Rear-Right, Standard): PWM=16, DIR=17
Motor motors[NUM_OF_MOTORS] = {Motor(5,4), Motor(9,8), 
                              Motor(11,12), Motor(16, 17)};

Car car{motors, NUM_OF_MOTORS};
Arm arm;
Radio radio;
int moves[3] = {0,0,0};

// Autonomous driving speed (PWM 0-255).
// Note: Motor RD is connected to pin 16 (non-timer pin on Mega 2560).
// Speeds >= 128 ensure pin 16 is driven HIGH so all 4 wheels engage reliably.
const int AUTO_SPEED = 200;

// Hardcoded Autonomous Sequence:
// Demonstrates differential drive behavior where the front Mecanum rollers
// relieve scrub while rear standard wheels maintain track stability.
void runAutonomousSequence() {
  Serial.println(F("\n========================================"));
  Serial.println(F(">>> Starting Autonomous Sequence <<<"));
  Serial.println(F("========================================"));

  // 1. Drive forward
  Serial.println(F("[Step 1] Driving forward for 2.0s..."));
  car.forward(AUTO_SPEED, 2000);

  // 2. Pause
  Serial.println(F("[Step 2] Pausing for 1.0s..."));
  car.pause(1000);

  // 3. Pivot turn
  // Pivots right around the stationary right rear wheel.
  // The front Mecanum rollers spin freely to relieve scrub during the arc.
  Serial.println(F("[Step 3] Pivot turning right for 1.5s..."));
  car.pivotTurnRight(AUTO_SPEED, 1500);

  // Brief settling pause
  car.pause(500);

  // 4. Back up
  Serial.println(F("[Step 4] Backing up for 2.0s..."));
  car.backward(AUTO_SPEED, 2000);

  // 5. Final stop
  Serial.println(F("[Step 5] Autonomous sequence complete. Stopping."));
  car.stop();
  Serial.println(F("========================================\n"));
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("Startup"));

  car.init();
  if(!arm.init()) Serial.println(F("Arm initializaiton has failed"));
  radio.init();

  // Safety countdown before autonomous execution
  Serial.println(F("Autonomous sequence starting in 2 seconds..."));
  delay(2000);

  // Execute hardcoded autonomous sequence
  runAutonomousSequence();
}

void loop() {
  // Allow re-triggering autonomous sequence via Serial Monitor by sending 'a'
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'a' || cmd == 'A') {
      runAutonomousSequence();
    }
  }

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
