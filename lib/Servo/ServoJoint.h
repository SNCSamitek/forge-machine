#pragma once
#include <Adafruit_PWMServoDriver.h>

struct ServoSpec {
    int minUs, maxUs;
    float rangeDeg;
    float maxDegPerSec;
};

class ServoJoint {
private:
    static Adafruit_PWMServoDriver pwm;
    static int servoIdGenerator;

    int servoId;
    ServoSpec spec;

    float current, target;
    unsigned long lastMs;

    void write(float deg);

public:
    static void initDriver();

    ServoJoint(const ServoSpec& spec);
    void begin(float startDeg);
    void update(float targetDeg);
};