#include "vex.h"
using namespace vex;
//function to run the intake
void Intake(int speed){
 conveyor.spin(fwd,speed,pct);
}
//function to stop the intake
void stop_Intake(){
 conveyor.stop(coast);
}
