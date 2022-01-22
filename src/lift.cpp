#include "cmath"
#include "vex.h"

using namespace vex;

motor_group Liftmotors(lftLift, rgtLift);
int ArmStat = 0;
double height = 0;

// Function to put the lift up
void lift(int speed) { Liftmotors.spin(fwd, speed, pct); }

// Function to stop the Lift
void lift_Stop() { Liftmotors.stop(hold); }
// Returns position of arm
double LftPos() {
  return ((lftLift.position(degrees) + rgtLift.position(degrees)) / 2);
}
// Sets arm position to specific degree
bool ArmOff(){
  if (ArmStat == 2 || ArmStat == 0){
    return(true);
  }
  else{
    return(false);
  }
}
int setArm(int Degrees) {
  double ArmError = (Degrees - LftPos());
  if (fabs(ArmError) <= 8 ){
    ArmStat = 2;
  }
  return(90);
}

void armPos(int Angle){
  height = Angle;
  ArmStat = 1;
}
//Arm task 
int ArmT(){
  while(1){
    if (ArmStat == 1){
      lift(setArm(height));
    }
    else if(ArmStat == 2){
      ArmStat =0;
    }
    else if(ArmStat == 0){
      lift_Stop();
    }
  }
  wait(20,msec);
  return(0);
}