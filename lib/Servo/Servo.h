#pragma once
#include <Adafruit_PWMServoDriver.h>

class ServoJoint {
private:
    Adafruit_PWMServoDriver* pwm;
    int channel;
    int minUs, maxUs;
    //270
    float rangeDeg;
    //speed limit
    float maxDegPerSec;
    //degrees
    float current, target;
    unsigned long lastMs;

    void write(float deg);

public:
    ServoJoint(Adafruit_PWMServoDriver* pwm, uint8_t channel,
               uint16_t minUs, uint16_t maxUs,
               float rangeDeg, float maxDegPerSec);

    void begin(float startDeg);
    void setTarget(float deg);
    void setTargetNormalized(float n);
    void update();
};