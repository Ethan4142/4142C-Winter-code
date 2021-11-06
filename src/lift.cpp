#include "vex.h"
#include "cmath"
using namespace vex;

motor_group Liftmotors (Lift);

//Function to put the lift up
void lift(int speed){
 Liftmotors.spin(fwd,speed,pct);
}

//Function to stop the Lift
void lift_Stop(){
  Liftmotors.stop(hold);
}
//Returns position of arm
int LftPos(){
  return LftPot.angle(degrees);
}
// Sets arm position to specific degree
void setArm (int Degrees){
  double Armp = 10;
 while(1){
 double ArmError = (Degrees - LftPos());
 lift(ArmError * Armp);
 if(std::abs(ArmError)<= 1){
   lift_Stop();
   break;
 }
}

}

