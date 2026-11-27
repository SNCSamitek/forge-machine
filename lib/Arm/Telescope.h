#pragma once
#include "ServoJoint.h"

class Telescope{
    private:
        ServoJoint servo;
    public:
        Telescope(ServoJoint servo, int length);
        void init();
        void writeAngles(float angle);
};