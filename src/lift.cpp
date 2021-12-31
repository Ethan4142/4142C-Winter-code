#include "vex.h"
#include "cmath"
using namespace vex;

motor_group Liftmotors (lftLift,rgtLift);

//Function to put the lift up
void lift(int speed){
 Liftmotors.spin(fwd,speed,pct);
}

//Function to stop the Lift
void lift_Stop(){
  Liftmotors.stop(hold);
}
//Returns position of arm
double LftPos(){
  return((lftLift.position(degrees) + rgtLift.position(degrees)) /2 );
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

