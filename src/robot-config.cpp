#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport Expander8 = triport(PORT8);
controller Controller1 = controller(primary);
motor lftTop = motor(PORT12, ratio18_1, false);
motor lftBot = motor(PORT18, ratio18_1, true);
motor rgtTop = motor(PORT20, ratio18_1, true);
motor rgtBot = motor(PORT4, ratio18_1, false);
motor conveyor = motor(PORT21, ratio18_1, true);
motor Lift = motor(PORT9, ratio36_1, false);
inertial Inertial = inertial(PORT3);
motor rgtFrnt = motor(PORT19, ratio18_1, false);
motor lftFrnt = motor(PORT14, ratio18_1, true);
encoder Rght = encoder(Brain.ThreeWirePort.E);
encoder Left = encoder(Brain.ThreeWirePort.G);
digital_out TilterLft = digital_out(Expander8.A);
digital_out TilterRgt = digital_out(Expander8.B);
digital_out MbgClawRgt = digital_out(Expander8.C);
digital_out MbgClawLft = digital_out(Expander8.D);
pot LftPot = pot(Brain.ThreeWirePort.D);

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