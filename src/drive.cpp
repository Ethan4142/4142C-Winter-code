#include "cmath"
#include "vex.h"

using namespace vex;
using namespace std;

// Constants ------------------------------------------------------------

// PID Driving Constants
double kp = 0.1;
double ki = 0.02;
double integralMaxDrive = 1000;
double integralMinDrive = -1000;
double kd = 0.03;
double DprevError = 0;
double DintegralError = 0;
double curError = 0;
// DriveTask Constant
double Target = 0;
double mspd = 0;
double ang = 0;
bool DriveStat ;
bool TurnStat ;
bool mbging;
// straightinin constant
double oKp = 0.7;
// PID Turning Constants
double TurnRor = 0;
double tP = 0.37;
double tI = 0.01;
double integralMaxTurn = 700;
double integralMinTurn = 5;
double tD = 0.15;
double TprevError = 0;
double TintegralError = 0;
double TcurError = 0;

double getAvg() { return ((Right + Left) / 2); }
double getRotation() { return(Inertial.rotation(degrees)); } //gets heading of inertial sensor in degrees moving to the left is negetive
double getHead(){ return(Inertial.heading()) ;} // degrees of robot 0 - 360
void resetDrive() {
  Right.resetRotation();
  Left.resetRotation();
}
bool DriveOff(){
  if(DriveStat || TurnStat){
    return(false);
  }
  else if(!DriveStat && !TurnStat){
    return(true);
  }
  return(0);
}
float align(){ return(oKp * ((getRotation() - TurnRor)- 0)); }
void resetPID(){
  resetDrive();
  Target= 0;
   mspd =0;
   ang = 0;
   TprevError = 0;
   TintegralError =0;
   DintegralError = 0;
   DprevError = 0;
}
double PID(double target, int mspeed, bool turning) {
  double pOut;
  double iOut;
  double dOut;
  double output;
  if (!turning) {
    double ticks = target * 820 ;
    curError = ticks - getAvg();

    pOut = kp * curError;

    DintegralError += curError;

    if (DintegralError >= integralMaxDrive) {
      DintegralError = integralMaxDrive;
    } else if (DintegralError <= integralMinDrive) {
      DintegralError = integralMinDrive;
    }
    iOut = ki * DintegralError;

    dOut = kd * DprevError;

    DprevError = curError;

    output = pOut + iOut + dOut;

    if (output > mspeed) {
      output = mspeed;
    } else if (output <= -mspeed) {
      output = -mspeed;
    }
    return (output);
  }
  else if(turning){
    TcurError = target - (getRotation() );
    
    pOut = tP * TcurError;

    TintegralError += TcurError;

    if(TintegralError >= integralMaxTurn){
      TintegralError = integralMaxTurn;
    }
    else if(TintegralError <= integralMinTurn){
      TintegralError = integralMinTurn;
    }
    
    iOut = tI * TintegralError;

    dOut = tD * TprevError;

    TprevError = TcurError;

    output = pOut + iOut +dOut;

    if(output >= mspeed){
      output = mspeed;
    }
    else if(output <= - mspeed){
      output = -mspeed;
    }
    return(output);
  }
  return(0);
}

void goTo(double target, int mspeed, bool turning){
  mspd = mspeed;
  if(turning){
    TurnStat = true;
    DriveStat = false;
    ang = target;
  }
  else if(!turning){
    DriveStat = true;
    TurnStat = false;
    Target = target;
  }

}
//-----------------------------------------------------------------------------------------
void goTombg(){
  mspd = 100;
  DriveStat = true;
  mbging = true;
  Target = 100;
}
int driveT() {
  while (1) {
    printf("curErroe turn %f",TcurError );
    if(DriveStat){
      leftDrive.spin(fwd,PID(Target,mspd,false) - align(),pct);
      rightDrive.spin(fwd,PID(Target,mspd,false) +align(),pct);
      if(abs(curError) <= 10){
        resetPID();
        DriveStat = false;
      }
    }
    else if(TurnStat){
      leftDrive.spin(fwd,PID(ang,mspd,true),pct);
      rightDrive.spin(fwd,-PID(ang,mspd,true),pct);
      if(abs(TcurError) <= 5){
        TurnRor = ang;
        resetPID();
        TurnStat = false; 
      }
    }
    else if(mbging){
      if(clawSen.objectDistance(mm) <= 30){
        DriveStat = false;
        resetPID();
        clamp(true);
      }
    }
    else if(!DriveStat && !TurnStat){
      leftDrive.stop(coast);
      rightDrive.stop(coast);
    }
  }
  wait(10, msec);
  return (0);
}
