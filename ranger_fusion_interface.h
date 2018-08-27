#ifndef FUSION_H
#define FUSION_H

#include <vector>

using std::vector;

// This is a forward declaration of the Ranger class (google it)
// It tells the RangerFusionInterface that such a class exists
// but does not specify its details
class Ranger;

// The RangerFusionInterface is a class which specifies the minimum
// required interface for your RangerFusion class your ranger fusion
// class must inherit from it
class RangerFusionInterface
{
public:
  RangerFusionInterface();

  // Accepts container of rangers as per requirement C2 of assignment 2
  virtual void setRangers(vector<Ranger*> rangers) = 0;

  // Returns a container of fused range readings as per C4 assignment 2
  virtual vector<double> getFusedRangeData() = 0;

  // Returns a container of raw/unfused range readings as per C5 assignment 2
  // vector of vectors
  virtual vector<vector<double> > getRawRangeData() = 0;
};

#endif // FUSION_H
