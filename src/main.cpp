// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// lftBack              motor         14
// rgtBack              motor         3
// conveyor             motor         8
// lftLift              motor         9
// Inertial             inertial      18
// rgtFrnt              motor         1
// lftFrnt              motor         12
// Rght                 encoder       A, B
// Left                 encoder       A, B
// Expander20           triport       20
// TiltLock             digital_out   H
// MbgClaw              digital_out   G
// rgtLift              motor         6
// Tilter               motor         19
// Midd                 encoder       E, F
// lftTop               motor         5
// rgtTop               motor         2
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"

using namespace vex;
competition Competition;
vex::task Odo;
vex::task Arm;
vex::task Con;
vex::task Mbg;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  reset_Drive();
  ResetArm();
  Inertial.calibrate();
  UnClamp();
  UnLock();
  Odo = task(DriveT);
  Arm = task(ArmT);
  Con = task(IntakeT);
  Mbg = task(TiltT);
  autoSelector();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  //  wait(5,sec);
  Inertial.setHeading(0, degrees);
  Auto();

  Odo.suspend();
  Arm.suspend();
  Mbg.suspend();
  Con.suspend();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(driverControlled);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
