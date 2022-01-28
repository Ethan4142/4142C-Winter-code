#include "vex.h"
competition Competition; //Instance of Competition set in here and included into main

int SelectedAuto = 0;

void waitTillOff(){ // Function that checks my tasks to see if their done and waits fro them to be done
  while (1){
    wait(600,msec);
    if(DriveOff() && ArmOff() && IntakeOff() && TiltOff()){
      break;
    }
    wait(20,msec);
  }
}

void autoSelector() {
 
 int width = 80; //Basic Rectangle Dimensions
 int height = 80;

 int TRx = 30; //Top Red Rect starting pos
 int TRy = 20;

 int BRx = 120; //Bot Red rect Starting pos
 int BRy = 20;

 int TBx = 210; //Top blue rect  Starting pos
 int TBy = 20;

 int BBx = 300; //Bot Blue rect Sratring pos
 int BBy = 20;

 int Sx = 160; //Skils rect Srating pos 
 int Sy = 120;

//Draws all of the rectancgles on the brain according to Start pos and Dimensions
 Brain.Screen.drawRectangle(TRx,TRy,width,height,red);
 Brain.Screen.drawRectangle(BRx,BRy,width,height,red);
 Brain.Screen.drawRectangle(TBx,TBy,width,height,blue);
 Brain.Screen.drawRectangle(BBx,BBy,width,height,blue);
 Brain.Screen.drawRectangle(Sx,Sy,width,height,yellow);
 while(1){
  if(Brain.Screen.pressing()){
   int selX = Brain.Screen.xPosition(); //Reports the X and Y of the Brain screen selection press
   int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))){ //Creates the Top Red rect selecting points
       SelectedAuto = 1 ;
       Brain.Screen.printAt(20,200, "Top Red");
      }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){ //Creates the Bot Red rect Selecting points
       SelectedAuto = 2;
       Brain.Screen.printAt(20,200, "Bot Red");
      }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){ //Creates the Top Blue rect Selecting points
        SelectedAuto = 3;
        Brain.Screen.printAt(20,200, "TopBlue");
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){ //Creates the Bot Blue rect Selecting points
        SelectedAuto = 4;
        Brain.Screen.printAt(20,200, "BotBlue");
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){ //Creates the SKills Skills rect selecting points
        SelectedAuto = 5;
        Brain.Screen.printAt(20,200, "Skills");
    }
  }
   else if(Competition.isEnabled()){
    break;
  }
 }
}

void Auto(){
  if(SelectedAuto == 1){
   resetTiltAng();
   //set the robot up facing towards the neutral gaol parallel or touching the wall
   //Top Red Auto
   //Red Side With alliance Goal on Awp line __ puts 3 match loads in Robot __ 
   setPos(-52,100,0); //Back towards the neutral goal
   TiltDwn();
   UnLock(); 
   wait(1.3,sec);
   Lock(); //picks up the neutral Goal
   TiltUp();
   setPos(24,90,0); //forwards towards the Goal on the Awp line
   waitTillOff();
   setPos(0,90,-90); //Turn towards the Awp Goal
   waitTillOff();
   setPos(18,80,0); //forwards to the Awp goal
   waitTillOff();
   Clamp();  //Picks up the Awp goal
   waitTillOff(); 
   setPos(-5,80,0); //rev a little away from wall
   waitTillOff();
   setPos(0,90,-90); //Turn to be facint back towards the driving station 
   waitTillOff();
   //only if you wanna do match loads during auto
   setPos(2,90,0); //forward for extra space
   wait(1.5,sec);
   Intake(100); //Intake on
   setPos(-30,40,0); //reverse Slowly to pick up match loads
   wait(2000,msec); // wait till done but Getto
   IntakeOff(); // intake off
   setPos(5,90,0);
   waitTillOff();
   TiltDwn();
  }
   else if(SelectedAuto == 2){
   resetTiltAng();
   // set up the robot near the corner of the field but a little crooked and aimed towards the neutral goal
   //Bottom Red Auto
   //Red side Auto with Alliance goal on the plat __ Puts 3 match loads in Robot __
   setPos(-60,100,0); //reverse To the neutral Goal
   TiltDwn();
   UnLock();
   wait(1.4,sec);
   Lock();  //Lock and pick up the neutral goal
   waitTillOff();
   setPos(53,90,0); //goes back towards the plat
   TiltUp();
   waitTillOff();
   setPos(0,55,-50); //turns towards the aliance goal
   waitTillOff();
   setPos(10,90,0); //forwards to the plat Goal
   waitTillOff();
   Clamp(); //clamp on to the plat goal
   setPos(-5,90,0);
   waitTillOff();
   setPos(0,80,-47);
   waitTillOff();
   //only if you wanna do match loads during the Auto period
   Intake(95); //intake on
   setPos(-20,30,0); //reverse Slowly to account for the match load rings
   wait(2000,msec); //getto wait till done
   IntakeOff(); //intake off
   
  }
  else if (SelectedAuto == 3){
   resetTiltAng();

    
   setPos(-50,90,0); //Back towards the neutral goal
   TiltDwn();
   UnLock(); 
   wait(1.5,sec);
   Lock(); //picks up the neutral Goal
   TiltUp();
   setPos(26,90,0); //forwards towards the Goal on the Awp line
   waitTillOff();
   setPos(0,90,-90); //Turn towards the Awp Goal
   wait(1,sec);
   setPos(18,80,0); //forwards to the Awp goal
   waitTillOff();
   Clamp();  //Picks up the Awp goal
   waitTillOff(); 
   setPos(-5,80,0); //rev a little away from wall
   waitTillOff();
   setPos(0,90,-90); //Turn to be facint back towards the driving station 
   waitTillOff();
   //only if you wanna do match loads during auto
   setPos(2,90,0); //forward for extra space
   wait(1.5,sec);
   Intake(100); //Intake on
   setPos(-30,40,0); //reverse Slowly to pick up match loads
   wait(2000,msec); // wait till done but Getto
   IntakeOff(); // intake off
   setPos(5,90,0);
   waitTillOff();
   TiltDwn();
  }
  else if(SelectedAuto == 4){
   resetTiltAng();
   // set up the robot near the corner of the field but a little crooked and aimed towards the neutral goal
   //Bottom Blue Auto
   //Blue side Auto with Alliance goal on the plat __ Puts 3 match loads in Robot __
   setPos(-64,100,0); //reverse To the neutral Goal
   TiltDwn();
   UnLock();
   wait(1.3,sec);
   Lock();  //Lock and pick up the neutral goal
   TiltUp();
   setPos(51,90,0); //goes back towards the plat
   waitTillOff();
   setPos(0,60,-55); //turns towards the aliance goal
   waitTillOff();
   setPos(10,90,0); //forwards to the plat Goal
   waitTillOff();
   Clamp(); //clamp on to the plat goal
   setPos(-5,60,0);
   waitTillOff();
   setPos(0,90,-50);
   waitTillOff();
   //only if you wanna do match loads during the Auto period
   setPos(-15,60,0); //reverse Slowly to account for the match load rings
   wait(2000,msec); //getto wait till done
   IntakeOff(); //intake off
  
  }
  else if(SelectedAuto == 5){
    //before We run Tilter reseter 
    resetTiltAng();
    //Skills Progammin here
    setPos(3,80,0); //forward to pick up aliiance goal off plat 
    waitTillOff();
    Clamp();
    setPos(-5,80,0);
    waitTillOff();
    setPos(0,90,89); // turn to neutral goal 
    waitTillOff();
    setPos(-50,100,0);
    TiltDwn();
    waitTillOff();
    Lock();
    setPos(-50,100,0);
    TiltUp();  //pick up neutral goal and drag to blue plat
    waitTillOff();
    setPos(0,90,-90);
    waitTillOff();
    setPos(38,90,0);
    waitTillOff();
    armPos(1380); //Arm up to plat level
    waitTillOff();
    setPos(0,40,-90); // slow turn towards plat 
    wait(200,msec);
    waitTillOff();
    setPos(10,60,0); // slow forward to plat to acc for weight
    waitTillOff();
    armPos(990); //Arm down hope
    waitTillOff();
    UnClamp(); //let Go of Goal
    wait(500,msec);
    waitTillOff();
    setPos(-10,80,0); // back away from plat
    waitTillOff();
    //second goal onto the blue plat
    setPos(0,50,90);
    waitTillOff();
    wait(600,msec);
    setPos(-4,90,0); //reverse a little away from plat
    waitTillOff();
    TiltDwn(); //but down the neutral we've been carrying 
    waitTillOff();
    UnLock();
    setPos(6,90,0); //forward to give space and let go fully from the tilter
    armPos(8); // arm down
    waitTillOff();
    TiltUp();
    waitTillOff();
    setPos(0,80,180); //turn to face the neutral goal 
    waitTillOff();
    setPos(25,80,0); // forward to the neutral goal 
    waitTillOff();
    Clamp(); // pick up the goal 
    armPos(300);
    waitTillOff();
    setPos(0,90,-180); // turn parallel the plat form with the goal 
    waitTillOff();
    setPos(33,80,0);
    waitTillOff();
    armPos(1280);
    waitTillOff();
    setPos(0,90,-90); //fully turn into the platform
    waitTillOff();
    setPos(20,90,0); //forward into the plat
    waitTillOff();
    UnClamp();
    wait(600,msec);
    setPos(-8,80,0); //reverses from Plat after putting 2nd goal on
    waitTillOff();
    //Pick up 3rd and 4th goal 
    //3rd goal: Alliance , 4th goal: Neutral
    setPos(0,90,-90);
    armPos(8);
    waitTillOff();
    setPos(58,90,0);
    waitTillOff();
    Clamp(); // picks up the 3rd goal 
    waitTillOff();
    setPos(-70,90,0);
    waitTillOff();
    setPos(0,90,45); //turn to the 4th goal at 45 angle 
    waitTillOff();
    TiltDwn();
    setPos(-40,100,0);
    waitTillOff();
    Lock(); //lock in the 3rd goal and tilt it 
    TiltUp();
    waitTillOff();
    setPos(0,90,-90);
    waitTillOff();
    setPos(50,90,0); //forward to the other plat form
    waitTillOff();
    //score the 3rd goal
    setPos(0,90,45);
    waitTillOff();
    setPos(15,90,0); //align with middle of plat
    waitTillOff();
    armPos(1280);
    waitTillOff();
    setPos(5,90,0);
    waitTillOff();
    UnClamp();
    wait(300,msec);
    setPos(-10,90,0); // back away from plat
    waitTillOff();
    //Grab The 4th and score
    setPos(0,90,45);
    waitTillOff();
    TiltDwn();
    waitTillOff();
    UnLock();
    wait(200,msec);
    setPos(6,90,0);
    armPos(8);
    waitTillOff();
    setPos(0,90,180);
    waitTillOff();
    setPos(20,90,0);
    waitTillOff();
    Clamp();
    waitTillOff();
    setPos(-10,90,0);
    waitTillOff();
    setPos(0,90,-135);
    waitTillOff();
    armPos(1280);
    waitTillOff();
    setPos(0,90,-90);
    waitTillOff();
    setPos(5,90,0);
    armPos(1000);
    waitTillOff();
    UnClamp();
    waitTillOff();
  
    







  }
}

