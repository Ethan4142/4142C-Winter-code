#include "vex.h"

int SelectedAuto = 0;

void waitTillOff(){ // Function that checks my tasks to see if their done and waits fro them to be done
  while (1){
    wait(30,msec);
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
       break;
      }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){ //Creates the Bot Red rect Selecting points
       SelectedAuto = 2;
       Brain.Screen.printAt(20,200, "Bot Red");
       break;
      }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){ //Creates the Top Blue rect Selecting points
        SelectedAuto = 3;
        Brain.Screen.printAt(20,200, "TopBlue");
        break;
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){ //Creates the Bot Blue rect Selecting points
        SelectedAuto = 4;
        Brain.Screen.printAt(20,200, "BotBlue");
        break;
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){ //Creates the SKills Skills rect selecting points
        SelectedAuto = 5;
        Brain.Screen.printAt(20,200, "Skills");
        break;
    }
  }
  else if(SelectedAuto > 0){
    break;
  }
 }
}

void Auto(){
  if(SelectedAuto == 1){
   //set the robot up facing towards the neutral gaol parallel or touching the wall
   //Top Red Auto
   //Red Side With alliance Goal on Awp line __ puts 3 match loads in Robot __ 
   setPos(-48,100,0); //Back towards the neutral goal
   TiltDwn(); 
   waitTillOff(); 
   Lock(); //picks up the neutral Goal
   TiltUp();
   setPos(20,90,0); //forwards towards the Goal on the Awp line
   waitTillOff();
   setPos(0,0,-90); //Turn towards the Awp Goal
   waitTillOff();
   setPos(20,80,0); //forwards to the Awp goal
   wait(30,msec);
   Clamp();  //Picks up the Awp goal
   waitTillOff(); 
   setPos(-8,90,0); //rev a little away from wall
   waitTillOff();
   setPos(0,90,-180); //Turn to be facint back towards the driving station 
   waitTillOff();
   //only if you wanna do match loads during auto
   setPos(15,90,0); //forward for extra space
   waitTillOff();
   Intake(95); //Intake on
   setPos(-20,40,0); //reverse Slowly to pick up match loads
   wait(2000,msec); // wait till done but Getto
   IntakeOff(); // intake off
  }
   else if(SelectedAuto == 2){
   // set up the robot near the corner of the field but a little crooked and aimed towards the neutral goal
   //Bottom Red Auto
   //Red side Auto with Alliance goal on the plat __ Puts 3 match loads in Robot __
   setPos(-50,100,0); //reverse To the neutral Goal
   TiltDwn();
   waitTillOff();
   Lock();  //Lock and pick up the neutral goal
   TiltUp();
   setPos(35,90,0); //goes back towards the plat
   waitTillOff();
   setPos(0,90,-90); //turns towards the aliance goal
   waitTillOff();
   setPos(15,90,0); //forwards to the plat Goal
   waitTillOff();
   Clamp(); //clamp on to the plat goal
   setPos(-20,90,0); //Reverse away from the plat 
   waitTillOff();
   //only if you wanna do match loads during the Auto period
   setPos(0,90,-125); //Turn to be parallel to the wall
   waitTillOff(); 
   setPos(15,90,0); //lil forward to give space for match laods
   waitTillOff();
   Intake(95); //intake on
   setPos(-30,60,0); //reverse Slowly to account for the match load rings
   wait(2000,msec); //getto wait till done
   IntakeOff(); //intake off

   


   
  }
}

