#include "vex.h"
using namespace vex;

void Tilt() {
  TilterLft.set(true);
  TilterRgt.set(true);
}
void UnTilt(){
  TilterLft.set(false);
  TilterRgt.set(false);
}

void Clamp(){
  MbgClawRgt.set(true);
  MbgClawLft.set(true);
}
void UnClamp(){
  MbgClawLft.set(false);
  MbgClawRgt.set(false);
}