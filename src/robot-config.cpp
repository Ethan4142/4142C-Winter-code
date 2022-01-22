#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport Expander20 = triport(PORT20);
controller Controller1 = controller(primary);
motor lftBack = motor(PORT14, ratio18_1, false);
motor rgtBack = motor(PORT3, ratio18_1, true);
motor conveyor = motor(PORT8, ratio18_1, true);
motor lftLift = motor(PORT9, ratio18_1, true);
inertial Inertial = inertial(PORT18);
motor rgtFrnt = motor(PORT1, ratio18_1, true);
motor lftFrnt = motor(PORT12, ratio18_1, false);
encoder Rght = encoder(Expander20.A);
encoder Left = encoder(Brain.ThreeWirePort.A);
digital_out TiltLock = digital_out(Expander20.H);
digital_out MbgClaw = digital_out(Expander20.G);
motor rgtLift = motor(PORT6, ratio18_1, false);
motor Tilter = motor(PORT19, ratio18_1, false);

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