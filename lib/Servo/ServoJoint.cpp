#include "ServoJoint.h"
#include "constants.h"

Adafruit_PWMServoDriver ServoJoint::pwm = Adafruit_PWMServoDriver();
int ServoJoint::servoIdGenerator = 0;


ServoJoint::ServoJoint(const ServoSpec& spec) : servoId(servoIdGenerator++), spec(spec), 
current(0), target(0), lastMs(0){}

void ServoJoint::initDriver(){
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(SERVO_FREQ);
}

void ServoJoint::begin(float startDeg){
    current = target = constrain(startDeg, 0.0f, spec.rangeDeg);
    lastMs = millis();
    write(current); 
}

void ServoJoint::write(float deg) {
    float us = spec.minUs + (deg / spec.rangeDeg) * (spec.maxUs - spec.minUs);
    pwm.writeMicroseconds(servoId, (uint16_t)us);
}

void ServoJoint::update(float targetDeg) {
    this->target = constrain(targetDeg, 0.0f, spec.rangeDeg);

    unsigned long now = millis();
    float dt = (now - lastMs) / 1000.0f;
    lastMs = now;
    if (dt > 0.1f) dt = 0.1f;

    float maxStep = spec.maxDegPerSec * dt;
    float diff = target - current;
    if (diff >  maxStep) diff =  maxStep;
    if (diff < -maxStep) diff = -maxStep;
    if (diff == 0.0f) return;

    current += diff;
    write(current);
}