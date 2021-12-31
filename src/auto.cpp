#include "vex.h"

int SelectedAuto = 1;

void autoSelector() {
 int SelectedAuto = 1;
 
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

  while (true) {
    if (Brain.Screen.pressing()){
     int selX = Brain.Screen.xPosition();
     int selY = Brain.Screen.yPosition();
      if ((selX > TRx && selX < (TRx + width)) && (selY > TRy && selY < (TRy + height))){
       SelectedAuto = 1 ;
     }
      else if((selX > BRx && selX < (BRx + width)) && (selY > BRy && selY < (BRy + height))){
       SelectedAuto = 2;
     }
      else if((selX > TBx && selX < (TBx + width)) && (selY > TBy && selY < (TBy + height))){
        SelectedAuto = 3;
      }
      else if((selX > BBx && selX <(BBx + width)) && (selY > BBy && selY < (BBy + height))){
        SelectedAuto = 4;
      }
      else if((selX > Sx && selX < (Sx + width)) && (selY > Sy && selY <(Sy + height))){
        SelectedAuto = 5;
      }
    }
    else{
      if (SelectedAuto == 1){
        Brain.Screen.printAt(10,200, "Top Red");
      }
      else if(SelectedAuto == 2){
        Brain.Screen.printAt(10,200, "Bot Red");
      }
      else if(SelectedAuto == 3){
        Brain.Screen.printAt(10,200, "TopBlue");
      }
      else if(SelectedAuto == 4){
        Brain.Screen.printAt(10,200, "BotBlue");
      }
      else if(SelectedAuto == 5){
        Brain.Screen.printAt(10,200, "Skills!");
      }
    }
  }
}

void Auto(){
  if(SelectedAuto == 1){
   printf("Donkey pong ");
   //TOP Red Auto
   setPost(20,90);
   waitUntil(DriveOff);
   setPost(0,90);
   
  }
   else if(SelectedAuto == 2){
   //Bottom Red Auto
   Drive(90,20);
   printf("donkey kong");
  }
}