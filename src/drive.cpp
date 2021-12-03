#include "vex.h"
#include "cmath"
using namespace vex;


motor_group lftMotors = {lftFrnt,lftTop,lftBot};

motor_group rgtMotors = {rgtFrnt,rgtTop,rgtBot};
//Constants ------------------------------------------------------------

//PID Driving Constants
 double kp = 1.1;
 double ki = 0.5;
 double integralMaxDrive = 1375;
 double integralMinDrive = 48;
 double kd = 0.9;
 double DprevError = 0;
 double DintegralError = 0;
 double curError = 0 ;
//DriveTask Constant
 double dist = 0;
 double mspd = 0;

// straightinin constant
 double oKp = 0.6;
//PID Turning Constants
 double TurnRor = 0 ;
 double turnKp = 0.6;
 double turnKi = 0.01;
 double integralMaxTurn = 500;
 double integralMinTurn = 5;
 double turnKd = 0.5;
 double TprevError = 0;
 double TintegralError = 0;
 double TcurError = 0;

//basic Motor functions--------------------------------------------------------
void LeftDrive(int Speed){
  lftMotors.spin(fwd,Speed,pct);
}
void RightDrive(int Speed){
  rgtMotors.spin(fwd,Speed,pct);
}
void stop_Drive(){  //Stops motor movement
 lftMotors.stop(coast);
 rgtMotors.stop(coast);
}
//Sensor funtions-------------------------------------------------------

void ResetTPID(){
 TintegralError = 0;
 TprevError = 0;
}
void ResetDPID(){
  DintegralError = 0;
  DprevError = 0;
}
void reset_Drive(){
  Left.setPosition(0,degrees);//resets integrated encoder positions
  Rght.setPosition(0,degrees);
}
int getAvg(){
//  return ((rgtFrnt.position(degrees)) +  (rgtTop.position(degrees)) + (rgtBot.position(degrees)) + (lftFrnt.position(degrees)) + (lftTop.position(degrees)) + (lftBot.position(degrees))) /4 ;
 return(Rght.position(degrees) + Left.position(degrees)) /2;
}
int curHeading(){
  return Inertial.rotation(degrees);
}
double CurAcc(){
  return Inertial.acceleration(yaxis);
}
//PID controllers----------------------------------------------------------------------
//Driving PID
double DrivePID(int mSpeed, int Inches){
   int ticks = (Inches/12.56) * 115 ; //chages inches into encoder ticks

   curError = ticks - getAvg(); //calculates the current error
  
   double outputP = kp * Inches; //calculates the proportional output

   DintegralError += curError; //calculates integral error
  if(DintegralError >= integralMaxDrive){ //limits integral numbers
    DintegralError = integralMaxDrive;
   }
   else if(DintegralError <= integralMinDrive){
   DintegralError = integralMinDrive;
   }
   double outputI = ki * DintegralError; //calculates integral output
  
   double outputD = kd * (curError - DprevError); //calculates Derivitive output

   DprevError = curError; //sets the current error to previous error

  double Output = outputP + outputI + outputD; //calculates Total PID Output
 if(Output >= mSpeed){
   Output = mSpeed;
 }
 else if(Output <= -mSpeed){
   Output = -mSpeed;
 }

 
 return(Output);
 }
//Driving straightening

double Align(){
  return(oKp * (curHeading() - TurnRor));
}


// Turning PID
double TurnPID(int mSpeed,int Degrees){
  TcurError = Degrees - ((curHeading())- TurnRor); //current heading error

  double ToutputP = turnKp * TcurError; //calculates Turning P output

  TintegralError += TcurError;
  if(TintegralError > integralMaxTurn){ //limits Integral 
    TintegralError = integralMaxTurn;
  }
  else if(TintegralError < integralMinTurn){
    TintegralError = integralMinTurn;
  }

  double ToutputI = turnKi * TintegralError; //calculates turning I output

  double ToutputD = turnKd * (TcurError - TprevError); //calculates turning D output

  TprevError = TcurError; //sets Previous output at end

  double Toutput = ToutputP + ToutputI + ToutputD; //calculates Total PID turning output 

  

  if(Toutput > mSpeed){ //speed limiter
    Toutput = mSpeed;
  }
  else if(Toutput < -mSpeed){
    Toutput = - mSpeed;
  }
  
  return (Toutput);
 }
//Movement functions--------------------------------------------------------------------
void Drive(int mspeed,int Distance){
  reset_Drive();
  while(1){
    printf("position %f ",curError); 
      LeftDrive(DrivePID(mspeed,Distance) - Align()); // sets robot motors to drive forward desired position and the align keeps it straight
      RightDrive(DrivePID(mspeed,Distance) + Align()); // left negetive, right positive

  if (std::abs(curError) <= 10 ){
    stop_Drive();
    ResetDPID();
    break;
    
   }
  }
}
void Turn(int mSpeed, int Angle){ 
 while (1){
   printf("Rwr %f", TcurError );
   if (true){ //sets the robot to turn right for less wasted motion
     LeftDrive(-TurnPID(mSpeed,Angle));
     RightDrive(TurnPID(mSpeed,Angle));
   }
   if (TcurError <= 0){
     TurnRor = Angle + TurnRor;
    //  printf("Rwr %f", TcurError );
     ResetTPID();
     stop_Drive();
     break;
   }
 }
}
//Driving Task-------------------------------------------------------------------

int DriveT(){
//PID Driving Constants
 double dist = 0;
 double mspd = 0;
 double kp = 1.1;
 double ki = 0.5;
 double integralMaxDrive = 1375;
 double integralMinDrive = 48;
 double kd = 0.9;
 double DprevError = 0;
 double DintegralError = 0;
//align const
 double oKp = 0.6;
//Turn Constant
 double Degree = 0;
 double TurnRor = 0 ;
 double turnKp = 0.6;
 double turnKi = 0.01;
 double integralMaxTurn = 500;
 double integralMinTurn = 5;
 double turnKd = 0.5;
 double TprevError = 0;
 double TintegralError = 0;
 double TcurError = 0;


 while(true){
 double inches = (dist/12.56) * 115;
 double Derror = inches - getAvg();
 
 double Poutput = Derror * kp;
 DintegralError += Derror ;
 if(DintegralError >= integralMaxDrive){ //limits integral numbers
    DintegralError = integralMaxDrive;
   }
 else if(DintegralError <= integralMinDrive){
   DintegralError = integralMinDrive;
   }
 double Ioutput = DintegralError * ki ;
 double Doutput = (Derror - DprevError) * kd ;
 
 double align = oKp * (curHeading() - 0);
 double output = (Poutput + Ioutput + Doutput);

 if (output> mspd){
   output = mspd;
 }
 else if(output < - mspd){
   output = - mspd;
 }


 LeftDrive(output - align);
 RightDrive(output + align);
 wait(25,msec);
 return(0);
 }
}
//Drive Function to activate task or smth
void setPost(int Distance, int speed){
  dist = Distance;
  mspd = speed;
}