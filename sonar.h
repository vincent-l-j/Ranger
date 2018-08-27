#ifndef SONAR_H
#define SONAR_H

#include "ranger.h"

class Sonar : public Ranger
{
public:
  Sonar();
  ~Sonar();

  int getNumberOfSamples();
};

#endif // SONAR_H
