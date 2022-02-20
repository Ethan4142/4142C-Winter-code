#include "vex.h"
using namespace vex;

void Lock() {
  TiltLock.set(false);
}
void UnLock(){
  TiltLock.set(true);
}

void Clamp(){
  MbgClaw.set(true);
}
void UnClamp(){
  MbgClaw.set(false);
}
