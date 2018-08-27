#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "ranger.h"
#include "radar.h"
#include "laser.h"
#include "ranger_fusion.h"
#include <iostream>             // streamsize;
#include <random>
#include <vector>


void showFixedParameters(Ranger &sensor);
void showNumberOfSamples(Ranger &sensor);
void askBaud(Ranger &sensor);
void askPort(Ranger &sensor);
void askFOV(Radar &sensor);
void askAngularResolution(Laser &sensor);
void askFusionType(RangerFusion &fusion);
void printReadings(Ranger &sensor);
void printRawData(RangerFusion &fusion);
void printFusedData(RangerFusion &fusion);


#endif // USER_INTERFACE_H
