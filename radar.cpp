// 11970720
// Vincent Jadraque

#include "radar.h"

Radar::Radar()
{
  setModel("RAD-001");
  setBaud(38400);               // default; 38400 or 115200
  setPort(0);                   // default; 0-20
  setFieldOfView(20);           // default; 20 or 40
  setMaxDistance(16.0);
  setNumberOfSamples(1);
}

Radar::~Radar()
{
  // for demonstration purposes only
}

int Radar::getNumberOfSamples()
{
  setNumberOfSamples(1);
  return number_of_samples_;
}


