#include "vex.h"
using namespace vex;

void intake(int speed){
  conveyor.spin(fwd,speed,pct);
}

void stopIntake(){
  conveyor.stop(coast);
}