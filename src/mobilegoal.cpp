#include "vex.h"
using namespace vex;

void Lock() {
  TiltLock.set(true);
}
void UnLock(){
  TiltLock.set(false);
}

void Clamp(){
  MbgClaw.set(true);
}
void UnClamp(){
  MbgClaw.set(false);
}
void Tilt (int speed){
  Tilter.spin(fwd,speed,pct);
}