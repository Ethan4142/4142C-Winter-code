using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lftTop;
extern motor lftBot;
extern motor rgtTop;
extern motor rgtBot;
extern motor conveyor;
extern motor Lift;
extern inertial Inertial;
extern motor rgtFrnt;
extern motor lftFrnt;
extern encoder Rght;
extern encoder Left;
extern triport Expander8;
extern digital_out TilterLft;
extern digital_out TilterRgt;
extern digital_out MbgClawRgt;
extern digital_out MbgClawLft;
extern pot LftPot;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );