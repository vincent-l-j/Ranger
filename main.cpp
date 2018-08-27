// 11970720
// Vincent Jadraque

#include <iostream>               // cout
#include <unistd.h>               // usleep

#include "ranger.h"
#include "laser.h"
#include "sonar.h"
#include "radar.h"
#include "user_interface.h"
#include "ranger_fusion.h"

using namespace std;

int main(int argc, char *argv[])
{
  // initialise laser sensor
  Laser laser;

  // query fixed parameters
  showFixedParameters(laser);
  cout << "Field of View ............. " << laser.getFieldOfView() << "\n\n" << endl;
  // configure rest of parameters
  askBaud(laser);
  askPort(laser);
  askAngularResolution(laser);
  showNumberOfSamples(laser);
  std::cout << "\n\n" << std::endl;
//  printReadings(laser);

  // initialise radar sensor
  Radar radar;

  // query fixed parameters
  showFixedParameters(radar);
  // configure rest of parameters
  askFOV(radar);
  askBaud(radar);
  askPort(radar);
  showNumberOfSamples(radar);
  std::cout << "\n\n" << std::endl;
//  printReadings(radar);

  // initialise sonar sensor
  Sonar sonar;

  // query fixed parameters
  showFixedParameters(sonar);
  cout << "Field of View ............. " << sonar.getFieldOfView() << "\n\n" << endl;
  // configure rest of parameters
  askBaud(sonar);
  askPort(sonar);
  showNumberOfSamples(sonar);
  std::cout << "\n\n" << std::endl;
//  printReadings(sonar);

  std::vector<Ranger*> rangers;
  rangers = {&laser, &radar, &sonar};

  RangerFusion fusion(rangers);
  int a = 1;
  askFusionType(fusion);

  while(1)
  {
    std::cout << "\n\nData set " << a << ":" << std::endl;
    printRawData(fusion);

    printFusedData(fusion);
    usleep(2000000);
    a++;
  }

  return 0;
}
