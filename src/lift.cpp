#include "cmath"
#include "vex.h"

using namespace vex;


bool ArmStat ;
double height = 0;
// Function to put the lift up
void armUp(int speed) { lift.spin(fwd, speed, pct); }

// Function to stop the Lift
void lift_Stop() { lift.stop(hold); }
// Returns position of arm
double LiftPos() {
  return(armPot.angle(degrees));
}
// Sets arm position to specific degree
bool ArmOff(){
  if (!ArmStat ){
    return(true);
  }
  else{
    return(false);
  }
}

void armPos(int Angle){
  height = Angle;
  ArmStat = true;
}
//Arm task 
int ArmT(){
  while(1){
    double ArmError = (height - LiftPos());
    if (ArmStat){
      printf("Arm height %f" , ArmError);
      if(ArmError > 2){
        lift.spin(fwd,90,pct);
      }
      else if(ArmError < -2){
        lift.spin(fwd,-90,pct);
      }
      else if (fabs(ArmError) <= 1){
        ArmStat = false;
      }
    }
    else if(!ArmStat){
      height = 0;
      lift_Stop();
    }
  }
  wait(20,msec);
  return(0);
}