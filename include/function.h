#ifndef _FUNCTION_H
#define _FUNCTION_H

using namespace vex;

void LeftDrive(int Speed);

void RightDrive(int Speed);

void stop_Drive();
//Function stops the drive motors

void waituntillDriveoff();
//Function to wait till drive movement is off

void Drive(int mSpeed,int Inches);
//Function to Drive using PID

void reset_Drive();
// function to reset drive encoders

int getAvg();
//Gets average of Drive encoder values

int curHeading();
//Reports the inertial's current position

void Intake(int Speed);
//Function to run the intake

void stop_Intake();
//Function to stop the intake

void lift(int speed);
//Function to move the lift

void lift_Stop();
//Function to Stop the lift motors 

void mbGintake(int speed);

void mbGouttake(int speed);

void Even_mbG();

void Stop_mbG();

void Lock();

void UnLock();

void Clamp();

void UnClamp();

double CurAcc();

double LftPos();

void Turn(int mSpeed,int Angle, bool Direction);

int DriveT();

void autoSelector();

void Auto();

void setPos(int Distance,int speed, int Ang);

void TiltSet(int Degree);

bool DriveOff();

bool ArmOff();

bool IntakeOff();

bool TiltOff();

void waitTillOff();

int ArmT();

int IntakeT();

int TiltT();

int TiltAng();

#endif