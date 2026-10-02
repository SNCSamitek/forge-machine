#include "Radio.h"
#include <Arduino.h>

const int maxValue  = 1792;
const int minValue  = 172;
const int zeroValue = 992;
const float newMax  = 1.0;
const float newMin  = -1.0;
const float deadzone = 0.2;

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
    float scale = (newMax - newMin) / (maxValue - minValue);
    float normalized = (((float) value) - zeroValue) * scale;

    if (abs(normalized) < deadzone)
        return 0.0;

    return constrain(normalized, newMin, newMax);
}

bool Radio::update(float* controllerData){
    if(!readControllerData())
        return false;

    for(int i = 0; i < NUMBER_OF_RECEIVER_CHANNELS; i++)
        controllerData[i] = normalizeControllerValue(data.ch[i]);
    
    return true;
}

