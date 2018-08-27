// 11970720
// Vincent Jadraque

#include "ranger.h"
#include "user_interface.h"
#include <limits>               // numeric_limits
#include <iomanip>              // setprecision


void showFixedParameters(Ranger &sensor)
{
  std::cout << "\n\n\nFixed parameters:\n";
  std::cout << "Model ..................... " << sensor.getModel() << std::endl;
  std::cout << "Max Distance .............. " << std::fixed << std::setprecision(1);
  std::cout << sensor.getMaxDistance() << " m" << std::endl;
  std::cout << "Min Distance .............. " << sensor.getMinDistance() << " m" << std::endl;
}

void showNumberOfSamples(Ranger &sensor)
{
  std::cout << "Number of samples ......... " << sensor.getNumberOfSamples() << std::endl;
}

void askFOV(Radar &sensor)
{
  std::cout << "\n\nPlease specify Field of View for radar sensor " << sensor.getModel() << std::endl;
  std::cout << "Enter '1' or '2' corresponding to the option you wish:" << std::endl;
  std::cout << "Option 1: 20 degrees" << std::endl;
  std::cout << "Option 2: 40 degrees" << std::endl;

  int test_FOV;

  while(!(std::cin >> test_FOV))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n\nPlease input numeric values only\n" << std::endl;

    std::cout << "Please specify Field of View.\nEnter '1' or '2' corresponding to the option you wish:" << std::endl;
    std::cout << "Option 1: 20 degrees" << std::endl;
    std::cout << "Option 2: 40 degrees" << std::endl;
  }

  // if values are sane, set field of view; else use default
  if(sensor.checkFieldOfView(test_FOV))
  {
    sensor.setFieldOfView(20 * test_FOV);
    std::cout << "Valid option. Using ";
  }
  else
  {
    std::cout << "Invalid option. Using default ";
  }
  std::cout << "field of view: " << sensor.getFieldOfView() << "\n\n" << std::endl;
}

void askBaud(Ranger &sensor)
{
  std::cout << "\n\nPlease specify baud rate for " << sensor.getModel() << std::endl;
  std::cout << "Enter '1' or '2' corresponding to the option you wish:" << std::endl;
  std::cout << "Option 1: 38400" << std::endl;
  std::cout << "Option 2: 115200" << std::endl;

  int test_baud;

  while(!(std::cin >> test_baud))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n\nPlease input numeric values only\n" << std::endl;

    std::cout << "Please specify baud rate for " << sensor.getModel() << std::endl;
    std::cout << "Enter '1' or '2' corresponding to the option you wish:" << std::endl;
    std::cout << "Option 1: 38400" << std::endl;
    std::cout << "Option 2: 115200" << std::endl;
  }

  // if values are sane, set baud; else use default
  // Option 1: 38400
  // Option 2: 115200
  // baud = 38400 * (2 * test_baud - 1)

  if(sensor.checkBaud(test_baud))
  {
    sensor.setBaud(38400 * (2 * test_baud - 1));
    std::cout << "Valid option. Using ";
  }
  else
  {
    std::cout << "Invalid option. Using default ";
  }
  std::cout << "baud rate: " << sensor.getBaud() << "\n\n" << std::endl;
}

void askPort(Ranger &sensor)
{
  std::cout << "\n\nPlease specify " << sensor.getModel();
  std::cout << " port number for /dev/ttyACMX ";
  std::cout << "\nwhere X is an integer from 0 to 20" << std::endl;
  std::cout << "Input X value:" << std::endl;

  int test_port;

  while(!(std::cin >> test_port))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n\nPlease input numeric values only\n" << std::endl;

    std::cout << "Please specify " << sensor.getModel();
    std::cout << " port number for /dev/ttyACMX ";
    std::cout << "\nwhere X is an integer from 0 to 20\n" << std::endl;
    std::cout << "Input X value:" << std::endl;
  }

  // if values are sane, set port; else use default
  if(sensor.checkPort(test_port))
  {
    sensor.setPort(test_port);
    std::cout << "Valid port number. Using ";
  }
  else
  {
    std::cout << "Specified port number out of range. Using default ";
  }
  std::cout << "sensor port: " << sensor.getPort() << std::endl;
}

void askAngularResolution(Laser &sensor)
{
  std::cout << "\n\nPlease specify angular resolution for laser sensor." << std::endl;
  std::cout << "Enter '1' or '2' corresponding to the option you wish:" << std::endl;
  std::cout << "Option 1: 15 degrees" << std::endl;
  std::cout << "Option 2: 30 degrees" << std::endl;

  int test_angular_resolution;

  while(!(std::cin >> test_angular_resolution))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n\nPlease input numeric values only\n" << std::endl;

    std::cout << "Please specify angular resolution for laser sensor." << std::endl;
    std::cout << "Enter '1' or '2' corresponding to the option you wish:" << std::endl;
    std::cout << "Option 1: 15 degrees" << std::endl;
    std::cout << "Option 2: 30 degrees" << std::endl;
  }

  // if values are sane, set field of view; else use default
  if(sensor.checkAngularResolution(test_angular_resolution))
  {
    sensor.setAngularResolution(15 * test_angular_resolution);
    std::cout << "Valid option. Using ";
  }
  else
  {
    std::cout << "Invalid option. Using default ";
  }
  std::cout << "angular resolution: " << sensor.getAngularResolution() << "\n\n" << std::endl;
}

void askFusionType(RangerFusion &fusion)
{
  std::cout << "Please specify fusion type by entering '0', '1', or '2' corresponding to the option you wish:" << std::endl;
  std::cout << "Option 0: minimum" << std::endl;
  std::cout << "Option 1: average" << std::endl;
  std::cout << "Option 2: maximum" << std::endl;

  int test_fusion_type;

  while(!(std::cin >> test_fusion_type))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n\nPlease input numeric values only\n" << std::endl;

    std::cout << "Please specify fusion type by entering '0', '1', or '2' corresponding to the option you wish:" << std::endl;
    std::cout << "Option 0: minimum" << std::endl;
    std::cout << "Option 1: average" << std::endl;
    std::cout << "Option 2: maximum" << std::endl;
  }

  // if values are sane, set field of view; else use default
  if(fusion.checkFusionType(test_fusion_type))
  {
    fusion.setFusionType(test_fusion_type);
    std::cout << "Valid option. Using ";
  }
  else
  {
    std::cout << "Invalid option. Using default ";
  }
  std::cout << "fusion type: " << fusion.getFusionType() << "\n\n" << std::endl;
}

void printReadings(Ranger &sensor)
{
  std::vector<double> v1;
  v1.resize(sensor.getNumberOfSamples());
  v1 = sensor.readSensor();
  for(auto i = v1.begin(); i != v1.end(); ++i)
    std::cout << *i << std::endl;
}



void printRawData(RangerFusion &fusion)
{
  vector<vector<double> > raw = fusion.getRawRangeData();
  vector<Ranger*> rangers = fusion.getRangers();

  int a = 0;
  int s = 0;

  std::cout << "Printing raw data:" << std::endl;

  for(vector<Ranger*>::iterator i = rangers.begin(); i != rangers.end(); i++, a++)
  {
    std::cout << (*i)->getModel() << std::endl;

    s = 1;

    for(vector<double>::iterator r = raw[a].begin(); r != raw[a].end(); r++, s++)
    {
      std::cout << "Sample " << s << ": " << *r << "m" << std::endl;
    }

    std::cout << std::endl;
  }
}

void printFusedData(RangerFusion &fusion)
{
  std::vector<double> fused;
  fused = fusion.getFusedRangeData();
  std::cout << "Printing fused data:" << std::endl;
  int s = 0;
  for(std::vector<double>::iterator i = fused.begin(); i != fused.end(); i++, s++)
  {
    std::cout << "Angle " << s * fusion.getRangers().at(0)->getAngularResolution() << ": " << *i << "m" << std::endl;
  }
}

