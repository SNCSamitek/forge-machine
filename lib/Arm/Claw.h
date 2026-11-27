#pragma once
#include "ServoJoint.h"
#include "vector.h"

class Claw{
    private:
        ServoJoint* servos;
        int num_of_servos;
    public:
        enum ClawItem{BOTTLE, COIN, CARDBOARD, POUCHES};
        enum Joint{WRIST, FINGER};

        Claw(ServoJoint* s, int num_of_servos);
        bool init();

        void close(uint8_t item);
        void moveWrist(float angle);
};