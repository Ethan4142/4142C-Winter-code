#include "vex.h"
#include"cmath"
void posTracking::updatePos(){
 posTracking::x = ((Rght + Left) /2);
 posTracking::y = Midd;
}

float posTracking::getX(){
  return(posTracking::x);
}

float posTracking::getY(){
  return(posTracking::y);
}