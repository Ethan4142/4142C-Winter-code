using namespace vex;


void mbg(bool take);

void clamp (bool pos);

int mbgFrnt(); //returns the distance of an object in front of the front distance sensor.

int mbgBack(); //returns the distacne of an object in front of the back distance sensor

void clawMbg(); //uses the Frnt distance sensor to detect when the mbg is in frnt of the robot and grabs it.

void goTombg();

void lokMbg();