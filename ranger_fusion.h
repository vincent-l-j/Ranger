#ifndef RANGERFUSION_H
#define RANGERFUSION_H

#define MIN 0
#define AVG 1
#define MAX 2

#include "ranger_fusion_interface.h"
#include "ranger.h"

class RangerFusion : public RangerFusionInterface
{
public:
  RangerFusion();
  RangerFusion(vector<Ranger*> rangers);
  ~RangerFusion();

  void setRangers(vector<Ranger*> rangers);
  vector<Ranger *> getRangers();
  vector<vector<double> > getRawRangeData();
  vector<double> getFusedRangeData();

  bool checkFusionType(int test_fusion_type);
  int getFusionType() const;
  void setFusionType(int fusion_type);

private:
  int fusion_type_;
  vector<Ranger*> rangers_;
  vector<vector<double> > raw_range_data_;
  vector<double> fused_range_data_;
};

#endif // RANGERFUSION_H
