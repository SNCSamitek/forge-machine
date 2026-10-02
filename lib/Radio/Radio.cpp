#include "Radio.h"
#include <Arduino.h>


Radio::Radio() : _sbus(Serial3){}

void Radio::init(){
    _sbus.begin(false);
}

void Radio::readCommands(int* moves, int size){
    _sbus.process();

    if(size > 0) moves[VX] = _sbus.getChannel(1);
    if(size > 1) moves[VY] = _sbus.getChannel(2);
    if(size > 2) moves[ROT] = _sbus.getChannel(4);
}