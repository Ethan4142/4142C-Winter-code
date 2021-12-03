/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// lftTop               motor         12              
// lftBot               motor         18              
// rgtTop               motor         20              
// rgtBot               motor         4               
// conveyor             motor         21              
// Lift                 motor         9               
// Inertial             inertial      3               
// rgtFrnt              motor         19              
// lftFrnt              motor         14              
// Rght                 encoder       E, F            
// Left                 encoder       G, H            
// Expander8            triport       8               
// TilterLft            digital_out   A               
// TilterRgt            digital_out   B               
// MbgClawRgt           digital_out   C               
// MbgClawLft           digital_out   D               
// LftPot               pot           D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
vex::task Odo;

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
  Inertial.calibrate();
  Inertial.setRotation(0,degrees);
  Clamp();
  UnTilt();
  Odo = task(DriveT);
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
 UnClamp();
 //wait(5,sec);

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

void usercontrol(void) {

  //Drive Table integer set
  int powr[23];
  int powr1[23];
  int yAxis;
  int xAxis;
  int rightSide;
  int leftSide;
  // int rightFrnt;
  // int rightBack;
  // int leftFrnt;
  // int leftBack;

  int index;
  int index1;
  
  bool Tilter = false;
  bool MbgClaw = false;

  while (1) {
    //Sensor Values Print on the brain
      printf("Position: %d", curHeading());

    Brain.Screen.printAt(20,160,  "Average Encoder Distance %d" , getAvg() ); //Prints Average    
    Brain.Screen.printAt(20,180,  "Inertial Rotation %f" , CurAcc() );
    Brain.Screen.printAt(20,200, "Ur %d", LftPos() );
    yAxis = Controller1.Axis3.value();
    xAxis = Controller1.Axis1.value();
    //---------------------------------Drive Table---------------------------------------------
    powr[0] = -100;
    powr[1] = -90;
    powr[2] = -80;
    powr[3] = -70;
    powr[4] = -60;
    powr[5] = -50;
    powr[6] = -40;
    powr[7] = -30;
    powr[8] = -20;
    powr[9] = -10;
    powr[10] = -5;
    powr[11] = 0;
    powr[12] = 5;
    powr[13] = 10;
    powr[14] = 20;
    powr[15] = 30;
    powr[16] = 40;
    powr[17] = 50;
    powr[18] = 60;
    powr[19] = 70;
    powr[20] = 80;
    powr[21] = 90;
    powr[22] = 100;
  
    powr1[0] = -100;
    powr1[1] = -90;
    powr1[2] = -80;
    powr1[3] = -70;
    powr1[4] = -60;
    powr1[5] = -50;
    powr1[6] = -40;
    powr1[7] = -30;
    powr1[8] = -20;
    powr1[9] = -10;
    powr1[10] = -5;
    powr1[11] = 0;
    powr1[12] = 5;
    powr1[13] = 10;
    powr1[14] = 20;
    powr1[15] = 30;
    powr1[16] = 40;
    powr1[17] = 50;
    powr1[18] = 60;
    powr1[19] = 70;
    powr1[20] = 80;
    powr1[21] = 90;
    powr1[22] = 100;
    //---------------------------------------Drive Logic-----------------------------------
    index = yAxis/12 + 11;
    index1 = xAxis/12 + 11;

    rightSide = (powr[index] - powr1[index1]);
    leftSide = (powr[index] + powr1[index1]); 

    RightDrive(rightSide);

    LeftDrive(leftSide);
    //Intake Controller
    if(Controller1.ButtonL1.pressing()==1){
      Intake(75);
    }
    else if(Controller1.ButtonL2.pressing()==1){
      Intake(-75);
    }
    else{
      stop_Intake();
    }
    //controller lift
    if(Controller1.ButtonR1.pressing()==1){
      lift(90);
    }
    else if(Controller1.ButtonR2.pressing()==1){
      lift(-90);
    }
    else{
      lift_Stop();
    }

    // Tilter Controller
    if(Controller1.ButtonX.pressing() == 1 ){
      if (!Tilter){
        Tilter = true;
        Tilt();
        wait(125,msec);
      }
      else if(Tilter){
        Tilter = false;
        UnTilt();
        wait(125,msec);
      }
    }
    // Mobile Goal Controller
     if(Controller1.ButtonA.pressing() ==  1){
       if(!MbgClaw){
         MbgClaw = true;
         Clamp();
         wait(125,msec);
       }
       else if(MbgClaw){
         MbgClaw = false;
         UnClamp();
         wait(125,msec);
       }
     }
  

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
  
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
