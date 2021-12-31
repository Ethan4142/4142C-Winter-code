using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor lftBack;
extern motor rgtBack;
extern motor conveyor;
extern motor lftLift;
extern inertial Inertial;
extern motor rgtFrnt;
extern motor lftFrnt;
extern encoder Rght;
extern encoder Left;
extern triport Expander20;
extern digital_out TiltLock;
extern digital_out MbgClaw;
extern pot LftPot;
extern motor rgtLift;
extern motor Tilter;
extern limit LimitSwitchH;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );