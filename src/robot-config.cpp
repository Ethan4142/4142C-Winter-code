#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport Expander21 = triport(PORT21);
controller Controller1 = controller(primary);
motor lftBack = motor(PORT9, ratio18_1, true);
motor rgtBack = motor(PORT8, ratio18_1, false);
motor conveyor = motor(PORT1, ratio6_1, false);
motor lift = motor(PORT3, ratio36_1, false);
inertial Inertial = inertial(PORT20);
motor rgtFrnt = motor(PORT14, ratio18_1, false);
motor lftFrnt = motor(PORT19, ratio18_1, true);
encoder Right = encoder(Expander21.A);
encoder Left = encoder(Expander21.C);
motor lftTop = motor(PORT18, ratio18_1, false);
motor rgtTop = motor(PORT12, ratio18_1, true);
potV2 armPot = potV2(Expander21.H);
digital_out mbgIntakeR = digital_out(Brain.ThreeWirePort.F);
digital_out mbgIntakeL = digital_out(Brain.ThreeWirePort.G);
digital_out claw = digital_out(Brain.ThreeWirePort.H);
digital_out lok = digital_out(Brain.ThreeWirePort.E);
vex::distance mbgSen = vex::distance(PORT5);
vex::distance clawSen = vex::distance(PORT10);
motor_group leftDrive = {lftFrnt, lftBack,lftTop};
motor_group rightDrive = {rgtFrnt, rgtBack,rgtTop};
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}