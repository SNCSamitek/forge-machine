#include "Telescope.h"


Telescope::Telescope(ServoJoint s, int length): servo(s){

}

void Telescope::init(){
    servo.begin(135.0f);
}

void Telescope::writeAngles(float angle){
    servo.update(angle);
}