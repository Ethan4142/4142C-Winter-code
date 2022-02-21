using namespace vex;
//------------------------------------------------------------------------------------------------
//----------------------------------Drive functions-----------------------------------------------
//Motion
void stop_Drive(); //function stops motors
void reset_Drive(); // function to reset drive encoders
int DriveT(); // Drive Task 
void setPos(int Distance,int speed, int Ang); // Sets desired position of Drive and runs The task
//Sensing
int getAvg(); //Gets average of Drive encoder values
double curHeading(); //Reports the inertial's current position
bool DriveOff(); // reports if Drive is Done running or not running
double CurAcc(); // reports the inertial sensors curent acceleration in newtons
//-----------------------------------------------------------------------------------------------
//------------------------------Lift/Arm functions-----------------------------------------------
//Motion
void armUp(int speed); //Function to set the lift motors to certain speed
void lift_Stop(); //Function to Stop the lift and set to hold motors 
int ArmT(); // Arm task
void armPos(int Angle); // sets desired position for the arm and activates task
//Sensing
void ResetArm(); // Resets internal encoders for the Arm motors used in pre auto
double LiftPos(); //gets the curent position of the lift
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

//--------------------------------------Total ROB Controlling Functions--------------------------

void waitTillOff();// Robot Wait untill all of the Tasks are done 

