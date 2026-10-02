#pragma once
#include <SBUS.h>
#include "constants.h"

class Radio{
    private:
        static const int FREQUENCY;
        SBUS _sbus;
    public:
        Radio();
        void init();
        void readCommands(int* moves, int size);
};