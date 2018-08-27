// 11970720
// Vincent Jadraque

#include "ranger.h"

#include <string.h>


Ranger::Ranger()
{
  min_distance_ = 0.2;
  setMeanRNG(6.0);
  setStdDevRNG(5.0);
  angular_resolution_ = 15;
}

Ranger::~Ranger()
{
  // demonstration only
}

std::string Ranger::getModel() const
{
  return model_;
}

bool Ranger::checkBaud(int baud)
{
  checkOption(baud);
}

int Ranger::getBaud() const
{
  return baud_;
}

void Ranger::setBaud(int baud)
{
  baud_ = baud;
}

// check whether port chosen is between 0 and 20
bool Ranger::checkPort(int port)
{
  if(port >= 0 && port < 21)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Ranger::setPort(int port)
{
  char portString[3] = {0};

  memset(port_, '\0', sizeof port_);
  strcat(port_, "/dev/ttyACM");

  sprintf(portString, "%d", port);

  strcat(port_, portString);
}

char *Ranger::getPort()
{
  return port_;
}

bool Ranger::checkFieldOfView(int test_FOV)
{
  checkOption(test_FOV);
}

int Ranger::getFieldOfView() const
{
  return field_of_view_;
}

void Ranger::setFieldOfView(int field_of_view)
{
  field_of_view_ = field_of_view;
}

bool Ranger::checkAngularResolution(int angular_resolution)
{
  checkOption(angular_resolution);
}

int Ranger::getAngularResolution()
{
  return angular_resolution_;
}

void Ranger::setAngularResolution(int angular_resolution)
{
  angular_resolution_ = angular_resolution;
}

double Ranger::getMaxDistance() const
{
  return max_distance_;
}

void Ranger::setMaxDistance(double max_distance)
{
  max_distance_ = max_distance;
}

double Ranger::getMinDistance() const
{
  return min_distance_;
}

void Ranger::setMinDistance(double min_distance)
{
  min_distance_ = min_distance;
}

int Ranger::getNumberOfSamples()
{
  number_of_samples_ = 1 + 2 * ((field_of_view_/2)/angular_resolution_);
  return number_of_samples_;
}

void Ranger::setNumberOfSamples(int number_of_samples)
{
  number_of_samples_ = number_of_samples;
}

double Ranger::getStdDevRNG() const
{
  return std_dev_RNG_;
}

std::vector<double> Ranger::readSensor()
{
  std::random_device rd;
  std::default_random_engine generator(rd());

  std::normal_distribution<double> normal(getMeanRNG(), getStdDevRNG());

  int n = getNumberOfSamples();
  std::vector<double> vi1 = {};

  for(int i = 0; i < n; i++)
  {
    // add check to limit max value
    double v = normal(generator);
    if(v > getMaxDistance())
      vi1.push_back(getMaxDistance());
    else if(v < getMinDistance())
      vi1.push_back(getMinDistance());
    else
      vi1.push_back(v);
  }
  return vi1;
}

void Ranger::setStdDevRNG(double std_dev_RNG)
{
  std_dev_RNG_ = std_dev_RNG;
}

double Ranger::getMeanRNG() const
{
  return mean_RNG_;
}

void Ranger::setMeanRNG(double mean_RNG)
{
  mean_RNG_ = mean_RNG;
}

bool Ranger::checkOption(int input)
{
  return (input == 1 || input == 2) ? true : false;
}

void Ranger::setModel(const std::string &model)
{
  model_ = model;
}
