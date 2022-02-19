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
double LiftPos() {
  // return ((lftLift.position(degrees) + rgtLift.position(degrees)) / 2);
  return(armPot.angle(degrees));
}
void ResetArm(){
 lftLift.setPosition(0,degrees);
 rgtLift.setPosition(0,degrees);
}
// Sets arm position to specific degree
bool ArmOff(){
  if (ArmStat == 0){
    return(true);
  }
  else{
    return(false);
  }
}

void armPos(int Angle){
  height = Angle;
  ArmStat = 1;
}
//Arm task 
int ArmT(){
  while(1){
    double ArmError = (height - LiftPos());
    if (ArmStat == 1){
      printf("Arm height %f" , ArmError);
      if(ArmError > 9){
        lftLift.spin(fwd,90,pct);
        rgtLift.spin(fwd,90,pct);
      }
      else if(ArmError < -9){
        lift(-90);
      }
      else if (fabs(ArmError) <= 8){
        ArmStat = 0;
      }
    }
    else if(ArmStat == 0){
      lift_Stop();
    }
  }
  wait(20,msec);
  return(0);
}