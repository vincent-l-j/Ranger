// 11970720
// Vincent Jadraque

#include "sonar.h"

Sonar::Sonar()
{
  setModel("SONX-001");
  setBaud(38400);               // default; 38400 or 115200
  setPort(0);                   // default; 0-20
  setFieldOfView(90);
  setMaxDistance(4.0);
  setNumberOfSamples(1);
}

Sonar::~Sonar()
{
  // for demonstration purposes only
}

int Sonar::getNumberOfSamples()
{
  setNumberOfSamples(1);
  return number_of_samples_;
}
