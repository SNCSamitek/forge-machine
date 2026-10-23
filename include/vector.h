#pragma once
#include <math.h>

struct vector{
  int x;
  int y;
  
  vector(int a, int b) : x(a), y(b){};

  inline int getHypo(){return sqrt(x*x + y*y);}
  inline int getAngle(){return atan2(y,x);}
};