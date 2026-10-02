#include "Radio.h"
#include <Arduino.h>

const int maxValue  = 1792;
const int minValue  = 172;
const int zeroValue = 992;
const int maxOut = 255;
const int minOut = -255;
const int deadzone = 8;

Radio::Radio(){}

void Radio::init(){
    sbus_rx.Begin();
}

bool Radio::readControllerData(){
    if(!sbus_rx.Read())
        return false;

    data = sbus_rx.data();
    return true;
}

float Radio::normalizeControllerValue(int value){
    float scale = (float)(maxOut - minOut) / (maxValue - minValue);
    int normalized = (((float) value) - zeroValue) * scale;

    if (abs(normalized) < deadzone)
        return 0.0;

    return constrain(normalized, minOut, maxOut);
}

bool Radio::update(float* controllerData){
    if(!readControllerData())
        return false;

    for(int i = 0; i < NUMBER_OF_RECEIVER_CHANNELS; i++)
        controllerData[i] = normalizeControllerValue(data.ch[i]);
    
    return true;
}

