#include "vex.h"

using namespace vex;
extern vex::task Odo;
extern vex::task Arm;
extern vex::task Con;
void driverControlled(void) {
  // Stop Tasks from running during the driver controlled period
  Odo.stop();
  Arm.stop();
  Con.stop();
  //Driver Controlling variables--
  int powr[23];
  int powr1[23];
  int yAxis;
  int xAxis;
  int rightSide;
  int leftSide;

  int index;
  int index1;

  bool conv = false;
  bool revConv = false;

  while (1) { // Controller Controlls while loop
    // Drive control table
    Brain.Screen.printAt(200,200, "CurHeading %f ", odometry.ang );
    yAxis = Controller1.Axis3.value();
    xAxis = Controller1.Axis1.value();
    odometry.updatePos();
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

    // Drive Calculations to Controls
    index = yAxis / 12 + 11;
    index1 = xAxis / 12 + 11;

    rightSide = (powr[index] - powr1[index1]);
    leftSide = (powr[index] + powr1[index1]);

    RightDrive(rightSide);

    LeftDrive(leftSide);

    // Intake Controller
    if (Controller1.ButtonL1.pressing() == 1) {
      if (!conv) {
        conveyor.spin(fwd, 90, pct);
        conv = true;
        wait(200, msec);
      }
      else if(conv){
        conveyor.stop(coast);
        conv = false;
        wait(200,msec);
      }
    } else if (Controller1.ButtonL2.pressing() == 1) {
      if (!revConv) {
        conveyor.spin(reverse, 900, pct);
        revConv = true;
        wait(200, msec);
      }
      else if(revConv){
        conveyor.stop(coast);
        revConv = false;
        wait(200,msec);
      }
    }
    // Mbg Intakes Controller

    //Arm Controller
    if (Controller1.ButtonR1.pressing()){
      lift.spin(fwd,90,pct);
    }
    else if(Controller1.ButtonR2.pressing()){
      lift.spin(fwd,-90,pct);
    }
    else{
      lift.stop(hold);
    }

  }
  wait(20, msec); // sleep to prevent wasted time ???
                  //
}