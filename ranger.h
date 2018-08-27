#ifndef RANGER_H
#define RANGER_H

#include <string>
#include <vector>
#include <random>

class Ranger
{
public:
  Ranger();
  ~Ranger();

  std::string getModel() const;

  bool checkBaud(int baud);
  int getBaud() const;
  void setBaud(int baud);

  bool checkPort(int port);
  char *getPort();
  void setPort(int port);

  bool checkFieldOfView(int test_FOV);
  int getFieldOfView() const;
  void setFieldOfView(int field_of_view);

  bool checkAngularResolution(int angular_resolution);
  int getAngularResolution();
  void setAngularResolution(int angular_resolution);

  double getMinDistance() const;
  double getMaxDistance() const;

  virtual int getNumberOfSamples();

  std::vector<double> readSensor();

protected:
  void setModel(const std::string &model);
  void setMinDistance(double min_distance);
  void setMaxDistance(double max_distance);
  virtual void setNumberOfSamples(int number_of_samples);
  double getMeanRNG() const;
  double getStdDevRNG() const;
  int number_of_samples_;                 // = 1+2*((FOV/2)/angular_res'n


private:
  void setMeanRNG(double mean_RNG);
  void setStdDevRNG(double std_dev_RNG);
  bool checkOption(int input);
  // variables representing parameter list
  std::string model_;
  int baud_;                              // configurable
  char port_[17];                         // configurable
  int field_of_view_;                     // degrees
  double max_distance_;                   // metres
  double mean_RNG_;                       // 6.0
  double std_dev_RNG_;                    // 5.0
  int angular_resolution_;                // degrees
  double min_distance_;                   // metres
};

#endif // RANGER_H
