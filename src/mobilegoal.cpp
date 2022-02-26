#include "vex.h"
using namespace vex;

void clawMbg(){
  while(1){
  if(clawSen.objectDistance(mm) <= 30){
    clamp(true);
    break;
  }
  }
}
void lokMbg(){
  while(1){
    if(mbgSen.objectDistance(mm) <= 30){
      lok.set(false);
      break;
    }
  }
}
void mbg(bool take){
  lok.set(take);
  wait(100,msec);
  mbgIntakeR.set(take);
  mbgIntakeL.set(take);
  
}

void clamp (bool pos){
  claw.set(pos);
}
