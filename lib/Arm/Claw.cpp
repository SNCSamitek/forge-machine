#include "Claw.h"

Claw::Claw(ServoJoint* servos, int num_of_servos): servos(servos), num_of_servos(num_of_servos){

}

bool Claw::init(){
    if(servos == nullptr || num_of_servos != 2)
        return false;

    for(int i = 0; i < num_of_servos; i++)
        servos[i].begin(135.0f);
    return true;
}

void Claw::close(uint8_t item){
    switch(item){
        case BOTTLE:
            this->servos[FINGER].update(420.0f); //write better angle later lmao
            break;
        case COIN:
            this->servos[FINGER].update(420.0f); //write better angle later lmao
            break;
        case CARDBOARD:
            this->servos[FINGER].update(420.0f); //write better angle later lmao
            break;
        case POUCHES:
            this->servos[FINGER].update(420.0f); //write better angle later lmao
            break;
        default:
            break;
    }
}

void Claw::moveWrist(float angle){
    this->servos[WRIST].update(angle);
}