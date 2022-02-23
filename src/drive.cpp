#include "cmath"
#include "vex.h"

using namespace vex;
using namespace std;

// Constants ------------------------------------------------------------

// PID Driving Constants
double kp = 0.11;
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
// straightinin constant
double oKp = 1.4;
// PID Turning Constants
double TurnRor = 0;
double tP = 0.76;
double tI = 0.02;
double integralMaxTurn = 500;
double integralMinTurn = 5;
double tD = 0.27;
double TprevError = 0;
double TintegralError = 0;
double TcurError = 0;

void Drive(){
  leftDrive.spin(fwd,PID(1,90,false),pct);
  rightDrive.spin(fwd,PID(1,90,false),pct);
}
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
    TcurError = target - (getRotation() - TurnRor);
    
    pOut = tP * TcurError;

    TintegralError += target;

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
int driveT() {
  while (1) {
    printf("curErroe turn %f",getAvg());
    if(DriveStat){
      leftDrive.spin(fwd,PID(Target,mspd,false) - align(),pct);
      rightDrive.spin(fwd,PID(Target,mspd,false) +align(),pct);
      if(abs(PID(Target,mspd,false)) <= 10){
        resetPID();
        DriveStat = false;
      }
    }
    else if(TurnStat){
      leftDrive.spin(fwd,PID(ang,mspd,true),pct);
      rightDrive.spin(fwd,-PID(ang,mspd,true),pct);
      if(abs(TcurError) <= 1){
        TurnRor = ang;
        resetPID();
        TurnStat = false; 
      }
    }
    else if(!DriveStat && !TurnStat){
      leftDrive.stop(coast);
      rightDrive.stop(coast);
    }
  }
  wait(20, msec);
  return (0);
}
