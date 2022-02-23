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
void liftMbg(){
  while(1){
    if(mbgBack() <20){
      mbg(true);
      break;
    }
  }
}
void mbg(bool take){
  mbgIntakeR.set(take);
  mbgIntakeL.set(take);
  lok.set(take);
}

void clamp (bool pos){
  claw.set(pos);
}