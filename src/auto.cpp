#include "vex.h"

int SelectedAuto = 0;

void waitTillOff(){
  while (1){
    wait(30,msec);
    if(DriveOff() && ArmOff() && IntakeOff() && TiltOff()){
      break;
    }
    wait(20,msec);
  }
}

void autoSelector() {
 
 int width = 80;
 int height = 80;

 int TRx = 30;
 int TRy = 20;

 int BRx = 120;
 int BRy = 20;

 int TBx = 210;
 int TBy = 20;

 int BBx = 300;
 int BBy = 20;

 int Sx = 160; 
 int Sy = 120;


 Brain.Screen.drawRectangle(TRx,TRy,width,height,red);
 Brain.Screen.drawRectangle(BRx,BRy,width,height,red);
 Brain.Screen.drawRectangle(TBx,TBy,width,height,blue);
 Brain.Screen.drawRectangle(BBx,BBy,width,height,blue);
 Brain.Screen.drawRectangle(Sx,Sy,width,height,yellow);
 while(1){
  if(Brain.Screen.pressing()){
   int selX = Brain.Screen.xPosition();
   int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))){
       SelectedAuto = 1 ;
       Brain.Screen.printAt(20,200, "Top Red");
       break;
      }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){
       SelectedAuto = 2;
       Brain.Screen.printAt(20,200, "Bot Red");
       break;
      }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){
        SelectedAuto = 3;
        Brain.Screen.printAt(20,200, "TopBlue");
        break;
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){
        SelectedAuto = 4;
        Brain.Screen.printAt(20,200, "BotBlue");
        break;
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){
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
   
   //TOP Red Auto
   setPos(-48,90,0);
   TiltSet(-990);
   waitTillOff();
   UnClamp();

   setPos(-24,90,0);
   TiltSet(-400);
   

  
   
  }
   else if(SelectedAuto == 2){
   //Bottom Red Auto

   Controller1.rumble(rumbleShort);
  }
}

