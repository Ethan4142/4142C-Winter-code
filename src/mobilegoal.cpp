#include "vex.h"
using namespace vex;

void Lock() {
  TiltLock.set(true);
}
void UnLock(){
  TiltLock.set(false);
}

void Clamp(){
  MbgClaw.set(true);
}
void UnClamp(){
  MbgClaw.set(false);
}
//Tilter Controlls / Tasks ------------------------------------
int Sped = 0;
int Ang = 0;
int TiltStat = 0;
int TiltAng(){
  return(Tilter.position(degrees));
}
int TiltEr(){
  return(Ang - TiltAng());
}
void TiltSet(int Degree){
  Ang = Degree;
  TiltStat = 1;
}
int TiltT(){
 while(1){
   if(TiltStat == 1){
     Tilter.spin(fwd,(0.5 * TiltEr()),pct);
   }
   else if(TiltStat == 0){
     Tilter.stop(hold);
   }
   if(abs(TiltEr()) <= 10){
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