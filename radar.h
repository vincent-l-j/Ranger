#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"

class Radar : public Ranger
{
public:
  Radar();
  ~Radar();

  int getNumberOfSamples();
};

#endif // RADAR_H
