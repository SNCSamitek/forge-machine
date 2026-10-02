#pragma once
#include "sbus.h"
#include "constants.h"

class Radio{
    private:
        static const int FREQUENCY;
        bfs::SbusRx sbus_rx{&Serial3};
        bfs::SbusData data;
    public:
        Radio();
        void init();

        bool readControllerData();
        float normalizeControllerValue(int value);
        bool update(float* controllerData);
};