#include "vex.h"

int SelectedAuto =10;

void waitTillOff() { // Function that checks my tasks to see if their done and waits fro them to be done
  while (1) {
    wait(300, msec);
    if (DriveOff() && ArmOff()) {
      break;
    }
    wait(20, msec);
  }
}

void autoSelector() {

  int width = 70; // Basic Rectangle Dimensions
  int height = 70;

  int TRx = 30; // Awp Line Rect starting pos
  int TRy = 20;

  int BRx = 110; // Plat Side rect Starting pos
  int BRy = 20;

  int TBx = 190; //? rect  Starting pos
  int TBy = 20;

  int BBx = 270; //? rect Starting pos
  int BBy = 20;

  int Sx = 150; // Skils rect Starting pos
  int Sy = 120;

  int WPx = 230; // Win point Starting Pos
  int WPy = 120;

  // Draws all of the rectancgles on the brain according to Start pos and Dimensions
  Brain.Screen.drawRectangle(TRx, TRy, width, height, yellow);
  Brain.Screen.drawRectangle(BRx, BRy, width, height, yellow);
  Brain.Screen.drawRectangle(TBx, TBy, width, height, black);
  Brain.Screen.drawRectangle(BBx, BBy, width, height, black);
  Brain.Screen.drawRectangle(Sx, Sy, width, height, purple);
  Brain.Screen.drawRectangle(WPx, WPy, width, height, green);
  while (1) {
    if (Brain.Screen.pressing()) {
      int selX = Brain.Screen.xPosition(); // Reports the X and Y of the Brain screen selection press
      int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))) { // Creates the AWP Line rect selecting points
        SelectedAuto = 1;
        Brain.Screen.printAt(20, 200, "Awp Line");
      } else if ((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))) { // Creates the Plat Side rect Selecting points
        SelectedAuto = 2;
        Brain.Screen.printAt(20, 200, "Plat Side");
      } else if ((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))) { // Creates the Top Blue rect Selecting points
        SelectedAuto = 3;
        Brain.Screen.printAt(20, 200, "Awp Blue");
      } else if ((selX > BBx && selX < (BBx + width)) && (selY > BBy && selY < (BBy + height))) { // Creates the Bot Blue rect Selecting points
        SelectedAuto = 4;
        Brain.Screen.printAt(20, 200, "Plat Blue");
      } else if ((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY < (Sy + height))) { // Creates the Skills rect selecting points
        SelectedAuto = 5;
        Brain.Screen.printAt(20, 200, "Skills");
      } else if ((selX > WPx && selX < (WPx + width)) && (selY > WPy && selY < (WPy + height))) { // creates a Win point rect selecting points
        SelectedAuto = 6;
        Brain.Screen.printAt(20, 200, " Win Point Auto");
      }
    } else if (Competition.isEnabled()) {
      break;
    }
  }
}

void Auto(void) {          // Auto function definition
 Inertial.setRotation(0, degrees);
  if (SelectedAuto == 1) { // Awp line Red side Autonomous score: neutral 1 , awp mbg taken, rings score avg: 4.
    goTo(2,100,false);
    clawMbg();
    waitTillOff();
    armPos(250); // lift arm a little to pull from other teams
    waitTillOff();
    goTo(-1, 90, false); // reverse to the Awp line mbg
    waitTillOff();
    goTo(-90, 90, true); // turn to the awp line mbg
    waitTillOff();
    mbg(true); // mbg back intake out
    waitTillOff();
    goTo(-0.4, 80, false); // reverse into the awp line mbg
    waitTillOff();
    mbg(false); // mbg back intake in
    waitTillOff();
    goTo(0.4, 80, false); // forward to line away from wall
    waitTillOff();
    goTo(-180, 80, true); // turn 180 facing the driver station left
    waitTillOff();
    armPos(289);       // arm up to intake rings
    intake(90);           // set intake on
    goTo(0.8, 40, false); // forward slowly to pick up rings "match loads"
    waitTillOff();
    stopIntake();
  } else if (SelectedAuto == 2) { // Plat Red side Autonomous Score: neutral 1 , plat Alliance Mbg taken , rings scored avg: 4
    goTo(2, 100, false); // rush to the neutral mbg
    clawMbg();
    armPos(220); // lift arm a little to pull from other teams
    waitTillOff();
    goTo(-1.3, 90, false); // reverse towards the plat mbg
    waitTillOff();
    goTo(-43, 90, true); // turn towards the plat mbg
    waitTillOff();
    mbg(true);             // mbg back intake out
    goTo(-0.7, 60, false); // revers towards the palt mbg
    waitTillOff();
    lokMbg();
    mbg(false);           // mbg back intake in
    goTo(0.4, 90, false); // forward away from plat
    waitTillOff();
    goTo(-190, 90, true); // turn 180 to the right towards the driver station
    waitTillOff();
    armPos(289); // lift arm up to start intaking rings
    intake(100);    // set intake on
    waitTillOff();
    goTo(0.8, 30, false); // forwards slowly towards the driver station to  get rings "match loads"
    waitTillOff();
    stopIntake();
  } else if (SelectedAuto == 6) { // Win point Autonoumus : score rings in both Alliance mbgs avg: 6
    mbg(true);             // puts back mbg intake down
    goTo(-0.4, 60, false); // reverse to pick up the mbg
    waitTillOff();
    mbg(false);
    goTo(0.6, 80, false);
    waitTillOff();
    goTo(90, 80, true);
    waitTillOff();
    goTo(1.4, 80, false);
    waitTillOff();
    goTo(180, 80, true);
    waitTillOff();
    armPos(250);
    intake(100);
    goTo(3, 60, false);
    waitTillOff();
    mbg(false);
    goTo(0.4, 90, false);
    waitTillOff();
    goTo(45, 90, true);
    waitTillOff();
    goTo(-0.7, 90, false);
    waitTillOff();
    goTo(0.4, 90, false);
    waitTillOff();

    goTo(90, 90, true);
    intake(90);
    waitTillOff();  
    goTo(0.8, 50, false);
  }
  if (SelectedAuto == 5) { // Program Skills Autonomous
  //-------------Blue Awp Line Mbg and First mid branch neutral mbg to Blue plat--------------------
    mbg(true);
    goTo(-0.86, 40, false); // reverse to the awp line  blue mbg 
    lokMbg();
    waitTillOff();
    mbg(false); //back mbg intake pull in the goal
    wait(600,msec);
    goTo(90, 100, true); //turn 90 degrees parallel to neutrals
    waitTillOff();
    goTo(0.9, 50, false);// go forward to line up with the neutral mobile goals
    waitTillOff();
    goTo(180, 90, true); // turn towards the neutral goals 
    waitTillOff();
    goTo(2.6, 80, false); //forward to the neutral goal
    clawMbg(); //claw down on the neutral goal
    waitTillOff();
    // goTo(1.6, 90, false); //forward to the blue platform
    // waitTillOff();
    goTo(85,90,true); //turn to be parallel with plat
    // armPos(287);
    waitTillOff();
    // intake(100);
    goTo(1.7, 90, false); //slowly go forward to mid plat
    waitTillOff();
    armPos(287);
    intake(100);
    waitTillOff();
    goTo(180, 70, true); //turn towards the platform 
    waitTillOff();
    stopIntake();
    goTo(0.1, 70, false); //lil nudge into the platform 
    waitTillOff();
    armPos(260); //arm down to put on the platform 
    waitTillOff();
    clamp(false); //let of the neutral mbg
    mbg(true);
    wait(500,msec);
    goTo(-0.4, 60, false); // reverse away from the platform
    waitTillOff();
    goTo(0.15,20,false);
    waitTillOff();
    goTo(0, 90, true); //turn towards the mbg that we dropped on the ground 
    armPos(184);
    waitTillOff();
    goTo(0.5, 80, false); //forward to the mbg we dropped
    clawMbg(); //clamp down on the mbg
    waitTillOff();
    armPos(265);
    goTo(190,80,true); //turn back towards the plat 
    waitTillOff();
    goTo(0.8,90,false); //nudge into the plat a little
    waitTillOff();
    clamp(false);//let go of the blue mbg
    waitTillOff();
    goTo(-0.01,80,false);
    waitTillOff();
    
    //------------Red Awp Line MBG and second mid branch neutral goal to plat-------------------
    goTo(270,70,true);
    waitTillOff();
    mbg(true);
    goTo(-1.85,70,false);
    lokMbg();
    waitTillOff();
    mbg(false);
    wait(500,msec);
    goTo(0.56,70,false);
    waitTillOff();
    goTo(0, 70, true); //turn 90 degrees parallel to neutrals
    armPos(184);
    waitTillOff();
    goTo(2.5, 70, false); //forward to the neutral goal
    clawMbg(); //claw down on the neutral goal
    waitTillOff();
    // goTo(1.4, 70, false); //forward to the blue platform
    // waitTillOff();
    goTo(-90,90,true); //turn to the pedals "rings"
    armPos(287);
    waitTillOff();
    intake(100);
    goTo(1.8, 70, false); //slowly go forward through the pedals "rings"
    waitTillOff();
    stopIntake();
    goTo(0, 90, true); //turn towards the platform 
    waitTillOff();
    goTo(0.8, 70, false); //lil nudge into the platform 
    waitTillOff();
    armPos(255); //arm down to put on the platform 
    waitTillOff();
    clamp(false); //let of the neutral mbg
    mbg(true);
    goTo(-0.8, 90, false); // reverse away from the platform
    waitTillOff();
    goTo(0.2,40,false);
    waitTillOff();
    goTo(180, 90, true); //turn towards the mbg that we dropped on the ground 
    armPos(184);
    waitTillOff();
    goTo(0.5, 90, false); //forward to the mbg we dropped
    clawMbg(); //clamp down on the mbg
    waitTillOff();
    armPos(250);
    goTo(0,90,true); //turn back towards the plat 
    waitTillOff();
    goTo(0.5,90,false); //nudge into the plat a little
    waitTillOff();
    clamp(false);//let go of the blue mbg
    waitTillOff();
    goTo(-0.4,90,false); //reverse away from the platform
    waitTillOff();
    //---------------final two mbg plat side red alliance mbg and tall neutral
    



  }
  else if(SelectedAuto == 10 ){
    //Testing Autonomous
    /*
    armPos(287);
    // intake(90);
    waitTillOff();
    // intake(90);
    armPos(250);
    waitTillOff();
    // intake(-90);
    armPos(184);
    */
    clawMbg();

    intake(10);
  }
}