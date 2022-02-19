#include "vex.h"
using namespace vex;

void Lock() {
  TiltLock.set(false);
}
void UnLock(){
  TiltLock.set(true);
}

void Clamp(){
  MbgClaw.set(true);
}
void UnClamp(){
  MbgClaw.set(false);
}
//Tilter Controlls / Tasks ------------------------------------
int Ang = 0;
int TiltStat = 0;
int tiltSpd = 0;
void resetTiltAng(){
  Tilter.setPosition(0,degrees);
}
int TiltAng(){
  return(Tilter.position(degrees));
}
int TiltEr(){
  return(Ang - TiltAng());
}
void TiltUp(int spd){
  Ang = -400;
  TiltStat = 2;
  tiltSpd = spd;
}
void TiltDwn(int spd){
  Ang = -990;
  TiltStat = 1;
  tiltSpd = spd;
}

int TiltT(){
 while(1){
   if(TiltStat == 1){
     Tilter.spin(fwd,-tiltSpd,pct);
   }
   else if(TiltStat == 2){
     Tilter.spin(fwd,tiltSpd,pct);
   }
   else if(TiltStat == 0){
     Tilter.stop(hold);
   }
   if(TiltStat == 1 && TiltAng() <= Ang){
     TiltStat = 0;
   }
   else if(TiltStat == 2 && TiltAng() >= Ang){
     TiltStat = 0;
   }
 }
 wait(20,msec);
 return(0);
}

bool TiltOff(){
  if(TiltStat == 0){
    return(true);
  }
  else{
    return(false);
  }
}