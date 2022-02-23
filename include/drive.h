using namespace vex;

int driveT();

void goTo(double target,int mspeed,bool turning);

double PID(double target,int mspeed,bool turning);

bool DriveOff();

double getAvg();

void Drive();