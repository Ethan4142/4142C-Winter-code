#include "vex.h"

int SelectedAuto = 1;

void waitTillOff(){ // Function that checks my tasks to see if their done and waits fro them to be done
  while (1){
    wait(290,msec);
    if(DriveOff() && ArmOff() ){
      break;
    }
    wait(20,msec);
  }
}

void autoSelector() {
 
 int width = 70; //Basic Rectangle Dimensions
 int height = 70;

 int TRx = 30; //Top Red Rect starting pos
 int TRy = 20;

 int BRx = 110; //Bot Red rect Starting pos
 int BRy = 20;

 int TBx = 190; //Top blue rect  Starting pos
 int TBy = 20;

 int BBx = 270; //Bot Blue rect Sratring pos
 int BBy = 20;

 int Sx = 150; //Skils rect Srating pos 
 int Sy = 120; 

 int WPx = 230;
 int WPy = 120;

 //Draws all of the rectancgles on the brain according to Start pos and Dimensions
 Brain.Screen.drawRectangle(TRx,TRy,width,height,red);
 Brain.Screen.drawRectangle(BRx,BRy,width,height,red);
 Brain.Screen.drawRectangle(TBx,TBy,width,height,blue);
 Brain.Screen.drawRectangle(BBx,BBy,width,height,blue);
 Brain.Screen.drawRectangle(Sx,Sy,width,height,yellow);
 Brain.Screen.drawRectangle(WPx,WPy,width,height,green);
 while(1){
  if(Brain.Screen.pressing()){
   int selX = Brain.Screen.xPosition(); //Reports the X and Y of the Brain screen selection press
   int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))){ //Creates the Top Red rect selecting points
       SelectedAuto = 1 ;
       Brain.Screen.printAt(20,200, "Awp Red");
      }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){ //Creates the Bot Red rect Selecting points
       SelectedAuto = 2;
       Brain.Screen.printAt(20,200, "Plat Red");
      }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){ //Creates the Top Blue rect Selecting points
        SelectedAuto = 3;
        Brain.Screen.printAt(20,200, "Awp Blue");
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){ //Creates the Bot Blue rect Selecting points
        SelectedAuto = 4;
        Brain.Screen.printAt(20,200, "Plat Blue");
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){ //Creates the SKills Skills rect selecting points
        SelectedAuto = 5;
        Brain.Screen.printAt(20,200, "Skills");
    }
    else if((selX >WPx && selX < (WPx + width)) && (selY > WPy && selY < (WPy + height))){
      SelectedAuto = 6;
      Brain.Screen.printAt(20,200, " Win Point Auto");
    }
  }
   else if(Competition.isEnabled()){
    break;
  }
 }
}

void Auto(void){ //Auto function definition
 if(SelectedAuto == 1){ //Awp line Red side Autonomous score: neutral 1 , awp mbg taken, rings score avg: 4.
  goTo(2,100,false);
  clawMbg();
  waitTillOff();
  goTo(-1,90,false);
  waitTillOff();
  goTo(-90,90,true);
  waitTillOff();
  mbg(true);
  waitTillOff();
  goTo(-0.4,80,false);
  waitTillOff();
  mbg(false);
  waitTillOff();
  goTo(0.6,80,false);
  waitTillOff();
  goTo(-180,80,true);
  waitTillOff();
  armPos(platUp);
  intake(90);
  goTo(0.8,40,false);
  waitTillOff();
  stopIntake();
  
 }
}