#pragma once
#include <math.h>

struct vector{
  int x;
  int y;
  
  vector(int a, int b) : x(a), y(b){};

  inline float getHypo() const {return sqrt(x*x + y*y);}
  inline float getAngle() const{return atan2(y,x);}
};