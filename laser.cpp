// 11970720
// Vincent Jadraque

#include "laser.h"

Laser::Laser()
{
  setModel("UTM-XXL");
  setBaud(38400);               // default; 38400 or 115200
  setPort(0);                   // default; 0-20
  setFieldOfView(180);
  setAngularResolution(15);     // default; 15 or 30
  setMaxDistance(8.0);
}

Laser::~Laser()
{
  // for demonstration only
}
