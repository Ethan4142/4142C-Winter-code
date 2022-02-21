#include "cmath"
#include "vex.h"

void posTracking::updatePos() { // sets class constants to real world values
  posTracking::x = (posTracking::getX() / 860);
  posTracking::y = (posTracking::getY() / 860);
  posTracking::ang = posTracking::getAng(false);
}
float posTracking::getX() { // gets Raw X value of robot "int encoder ticks"
  return ((cos(posTracking::getAng(true)) * ((Right + Left) / 2)));
}

float posTracking::getY() { // gets Raw Y value of robot "in ecoder ticks"
  return ((sin(posTracking::getAng(true)) * ((Right + Left) / 2)));
}
float posTracking::getAng(
    bool radian) { // Translates Curheading from degrees to radians
  if (radian) {
    return ((Inertial.heading() * M_PI / 180) + (posTracking::sAng * (M_PI / 180))); // gets Angle of robot in radians
  } else if (!radian) {
    float Degree = Inertial.heading() + posTracking::sAng;
    if (Degree > 360) {
      Degree = Degree - 360;
    }
    return (
        Degree); // gets Angle of robot in degrees limited to a range of (0-360)
  } else
    return (0);
}
float posTracking::PID(float target, bool turning, bool axis) {
  double error;
  float pOut;
  float iOut;
  double iEr;
  double iLimit;
  float dOut;
  double preEr;
  float output;

  if (!turning && axis) {
   error = target - posTracking::getX();

   pOut = posTracking::dP * error;
   
   iEr += error;
   if(iEr >= 4300 ){
     iEr = 4300;
   }
   else if(iEr <= -4300){
     iEr = -4300;
   }   
   iOut = posTracking::dI * iEr ;
   
   dOut = posTracking::dD * preEr;

   preEr = error;

   output = pOut + iOut + dOut ;
  } 
  else if(!turning && !axis){
    error = target - posTracking::getY();

   pOut = posTracking::dP * error;
   
   iEr += error;
   if(iEr >= 4300 ){
     iEr = 4300;
   }
   else if(iEr <= -4300){
     iEr = -4300;
   }   
   iOut = posTracking::dI * iEr ;
   
   dOut = posTracking::dD * preEr;

   preEr = error;

   output = pOut + iOut + dOut ;
  }
  else if (turning) {

  }
  //finally returns PID out put for spesific Axis
  return(output);
}
