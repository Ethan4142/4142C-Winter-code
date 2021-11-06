#ifndef _FUNCTION_H
#define _FUNCTION_H
using namespace vex;

void LeftDrive(int Speed);

void RightDrive(int Speed);

void stop_Drive();
//Function stops the drive motors

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

void Spin(int speed);

void Spin180();

void Even_Spin();

void Stop_Spin();

void Tilt();

void UnTilt();

void Clamp();

void UnClamp();

double CurAcc();

void setArm(int degree);

int LftPos();

void Turn(int mSpeed,int Angle, bool Direction);
#endif