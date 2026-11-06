#pragma once
#include <math.h>

struct vector{
  float x;
  float y;

  vector(float a, float b) : x(a), y(b){};

  inline float getHypo() const {return sqrt(x*x + y*y);}
  inline float getAngle() const{return atan2(y,x);}
};
