#ifndef _FUNCTION_H
#define _FUNCTION_H

using namespace vex;
//------------------------------------------------------------------------------------------------
//----------------------------------Drive functions-----------------------------------------------
//Motion
void LeftDrive(int Speed); //set drive motors to certain power
void RightDrive(int Speed); //set drive motors to certain power
void stop_Drive(); //function stops motors
void reset_Drive(); // function to reset drive encoders
int DriveT(); // Drive Task 
void setPos(int Distance,int speed, int Ang); // Sets desired position of Drive and runs The task
//Sensing
int getAvg(); //Gets average of Drive encoder values
int curHeading(); //Reports the inertial's current position
bool DriveOff(); // reports if Drive is Done running or not running
double CurAcc(); // reports the inertial sensors curent acceleration in newtons
//-----------------------------------------------------------------------------------------------
//------------------------------Lift/Arm functions-----------------------------------------------
//Motion
void lift(int speed); //Function to set the lift motors to certain speed
void lift_Stop(); //Function to Stop the lift and set to hold motors 
int ArmT(); // Arm task
void armPos(int Angle); // sets desired position for the arm and activates task
void Clamp(); //Sets the Pnematic Clamp on the Lift to Clamp
void UnClamp(); //Sets the Pnematic Ckamp on the Lift to Unclamp
//Sensing
double LftPos(); //gets the curent position of the lift
bool ArmOff(); // checks to see if the Arm task is done moving
//------------------------------------------------------------------------------------------------
//----------------------------------Conveyor Functions--------------------------------------------
//Motion
void Intake(int Speed); // Function to set conveyor speed
void stop_Intake();// Function to stop the conveyor 
int IntakeT(); // Task to control the converyor
//sensing
bool IntakeOff();// checks to see if thei ntake has stoped its movement
//-----------------------------------------------------------------------------------------------
//---------------------------------Mbg and friends Functions-------------------------------------
//Back tilter Motion
int TiltT(); //Tilter Task
void resetTiltAng();
void TiltUp(); //Tilter function to start task and set the Tilter into the Up pos
void TiltDwn(); //Tilter Function to start task and set the tilter into the down pos
void Lock(); //Sets the Pnumatic for the tilter to lock
void UnLock(); // Sets the Pneumatic fro the tilter to unlock
//Back Tilter Sensing
bool TiltOff(); //Checks to see if the tilter is done
int TiltAng(); //Reports the Tilters curent Ang
//--------------------------------------------------------------------------------------------------
//--------------------------------------Total ROB Controlling Functions--------------------------
void autoSelector(); //Runs the AutoSelector to select and set the pos of the robot
void Auto(); // Runs the Auto according to what was selected on the Auto Selector

void waitTillOff();// Robot Wait untill all of the Tasks are done 


#endif