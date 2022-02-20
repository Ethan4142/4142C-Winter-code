#include "vex.h"
#include"cmath"
void posTracking::updatePos(){
 posTracking::x = ((Right + Left) /2);
 posTracking::y = Midd;
 posTracking::ang = Inertial.heading();
}

float posTracking::getX(){
  return(((cos(posTracking::getAng(true)) * (0) )));
}

float posTracking::getY(){
  return(posTracking::y);
}

float posTracking::getAng(bool radian){ //Translates Curheading from degrees to radians
 if (radian){
   return((Inertial.heading() * M_PI/180) + posTracking::sAng);
 }
 else if(!radian){
   return(Inertial.heading() + posTracking::sAng);
 }
 else
 return(0);
}
float posTracking::PID(float target){
 float output;

 double error = target - posTracking::getX();

 float pOut = error * posTracking::dP;
 

 float iOut = 0;


 return(output);
}
