#include "cmath"
#include "vex.h"

using namespace vex;

motor_group lftMotors = {lftFrnt, lftBack};

motor_group rgtMotors = {rgtFrnt, rgtBack};
// Constants ------------------------------------------------------------

// PID Driving Constants
double kp = 0.4;
double ki = 0.002;
double integralMaxDrive = 2233;
double integralMinDrive = -2233;
double kd = 0.25;
double DprevError = 0;
double DintegralError = 0;
double curError = 0 ;
// DriveTask Constant
double dist = 0;
double mspd = 0;
double Degree = 0;
int DriveStat = 0;
int TurnStat = 0;
// straightinin constant
double oKp = 1.4;
// PID Turning Constants
double TurnRor = 0;
double turnKp = 0.90;
double turnKi = 0.01;
double integralMaxTurn = 500;
double integralMinTurn = 5;
double turnKd = 0.28;
double TprevError = 0;
double TintegralError = 0;
double TcurError = 0;

// basic Motor functions--------------------------------------------------------
void LeftDrive(int Speed) { lftMotors.spin(fwd, Speed, pct); }
void RightDrive(int Speed) { rgtMotors.spin(fwd, Speed, pct); }
void stop_Drive() { // Stops motor movement
  lftMotors.stop(coast);
  rgtMotors.stop(coast);
}
// Sensor funtions-------------------------------------------------------
void EndTPID() {
  TintegralError = 0;
  TprevError = 0;
  TurnRor = Degree + TurnRor;
  Degree = 0;
}
void ResetDPID() {
  DintegralError = 0;
  DprevError = 0;
  dist = 0;
  curError = 0;
  reset_Drive();
}
void reset_Drive() {
  Left.setPosition(0, degrees); // resets integrated encoder positions
  Rght.setPosition(0, degrees);
}
int getAvg() {
  return ((Rght.position(degrees) + Left.position(degrees)) / 2);
}
double curHeading() { return Inertial.rotation(degrees); }
double CurAcc() { return Inertial.acceleration(yaxis); }

bool DriveOff(){
  if ((DriveStat == 0) && (TurnStat == 0)){ //
    return(true);
  }
  else{
    return(false);
  }
}
// PID
// controllers----------------------------------------------------------------------
// Driving PID
double DrivePID(int mSpeed, int Inches) {
  int ticks = (Inches / 12.9525) * 230; // chages inches into encoder ticks

  curError = ticks - getAvg(); // calculates the current error

  double outputP = kp * curError; // calculates the proportional output

  DintegralError += curError;               // calculates integral error
  if (DintegralError >= integralMaxDrive) { // limits integral numbers
    DintegralError = integralMaxDrive;
  } else if (DintegralError <= integralMinDrive) {
    DintegralError = integralMinDrive;
  }
  double outputI = ki * DintegralError; // calculates integral output

  double outputD = kd * (curError - DprevError); // calculates Derivitive output

  DprevError = curError; // sets the current error to previous error

  double Output = outputP + outputI + outputD; // calculates Total PID Output
  if (Output >= mSpeed) {
    Output = mSpeed;
  } else if (Output <= -mSpeed) {
    Output = -mSpeed;
  }

 if (fabs(curError) <= 10){
   DriveStat = 0;
 }
  return (Output);
}
// Driving straightening

double Align() { return (oKp * (curHeading() - TurnRor)); }

// Turning PID
double TurnPID(int mSpeed, int Angle) {
  TcurError = Angle - ((curHeading()) - TurnRor); // current heading error

  double ToutputP = turnKp * TcurError; // calculates Turning P output

  TintegralError += TcurError;
  if (TintegralError > integralMaxTurn) { // limits Integral
    TintegralError = integralMaxTurn;
  } else if (TintegralError < integralMinTurn) {
    TintegralError = integralMinTurn;
  }

  double ToutputI = turnKi * TintegralError; // calculates turning I output

  double ToutputD = turnKd * (TcurError - TprevError); // calculates turning D output

  TprevError = TcurError; // sets Previous output at end

  double Toutput =
      ToutputP + ToutputI + ToutputD; // calculates Total PID turning output

  if (Toutput > mSpeed) { // speed limiter
    Toutput = mSpeed;
  } else if (Toutput < -mSpeed) {
    Toutput = -mSpeed;
  }

  if(fabs(TcurError) <= 1.9){ //sets the Task to done mode 
    TurnStat = 0;
  }

  return (Toutput);
}

// Drive Function to activate task or smth-------------------------------
void setPos(int Distance, int speed,int Ang) {
  if(abs(Distance) > 0){ //if the Drive pos wanna be changed 
    DriveStat = 1;  //makes the Drive Task activate
    dist = Distance;
    mspd =speed;
  }
  else if(abs(Ang) > 0){ //if the angle wants to be changed
    TurnStat  = 1; //Makes the Turn Taks activate
    mspd = speed;
    Degree = Ang;
  }
}

// Task-------------------------------------------------------------------

int DriveT() {

  while(1){
    if(DriveStat == 1){
     LeftDrive( DrivePID(mspd,dist) - Align());
     RightDrive( DrivePID(mspd,dist) + Align());
     printf("Error %f", curError );
     TurnStat = 0;
    }
    if(TurnStat == 1){
      LeftDrive(TurnPID(mspd,Degree));
      RightDrive(-TurnPID(mspd,Degree));
      printf("Error %f", TcurError);
      DriveStat = 0;
    }
    if (DriveStat == 0 && TurnStat == 0 ){
      EndTPID();
      ResetDPID();
     stop_Drive();
    }
  } 
  wait(20, msec);
  return (0);
}
