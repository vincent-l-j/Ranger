#include "ranger_fusion.h"
#include <algorithm>

RangerFusion::RangerFusion()
{
  // fusion type (0 - min; 1 - avg; 2 - max) will be set to average
  setFusionType(AVG);
}

RangerFusion::RangerFusion(vector<Ranger *> rangers)
{
  // fusion type (0 - min; 1 - avg; 2 - max) will be set to average
  setFusionType(AVG);
  setRangers(rangers);
}

RangerFusion::~RangerFusion()
{
  // for demonstration purposes only
}

void RangerFusion::setRangers(vector<Ranger *> rangers)
{
  // sort rangers by field of view (large to small)
  std::sort (rangers.begin(), rangers.end(),
      [](Ranger * a, Ranger * b){return b->getFieldOfView() < a->getFieldOfView();}
  );
  rangers_ = rangers;
}

vector<Ranger *> RangerFusion::getRangers()
{
  return rangers_;
}

vector<vector<double> > RangerFusion::getRawRangeData()
{
//  for(auto r : rangers_)
//  {
//    raw_range_data_.push_back(r->readSensor());
//  }
  raw_range_data_.clear();

  for(vector<Ranger *>::iterator i = rangers_.begin(); i != rangers_.end(); i++)
  {
    raw_range_data_.push_back((*i)->readSensor());
  }
  return raw_range_data_;
}

vector<double> RangerFusion::getFusedRangeData()
{
  // make vector for how many times the radar and sonar sensors' field of view
  // overlaps with the laser's samples
  // e.g. if angular res'n of laser is 15, and radar FOV is 20,
  //      laser has 13 samples, radar overlaps once, and sonar overlaps 3 times
  //      so NoS = {13, 1, 3};
  fused_range_data_.clear();

  std::vector<int> overlap;
  for(int n = 0; n < rangers_.size(); n++)
  {
    overlap.push_back(1 + 2 * ((rangers_.at(n)->getFieldOfView()/2)/rangers_.at(n)->getAngularResolution()));
  }

  int a = 0;

  int s = 1;
  int r = 2;

  int ol_s = (overlap.at(0) - overlap.at(s))/2;
  int ol_r = (overlap.at(0) - overlap.at(r))/2;

  double raw_s = raw_range_data_.at(s).at(0);
  double raw_r = raw_range_data_.at(r).at(0);

  double e;

  for(vector<double>::iterator i = raw_range_data_.at(0).begin(); i != raw_range_data_.at(0).end(); i++, a++)
  {
    e = *i;
    if( (a >= ol_s) && (a < ol_s + overlap.at(s)) )
    {
      switch(fusion_type_)
      {
        case MIN: e = std::min((*i), raw_s); break;
        case AVG: e = ((*i) + raw_s)/2.0; break;
        case MAX: e = std::max((*i), raw_s); break;
      }
    }
    if( (a >= ol_r) && (a < ol_r + overlap.at(r)) )
    {
      switch(fusion_type_)
      {
        case MIN: e = std::min(e, raw_r); break;
        case AVG: e = (2.0 * e + raw_r)/3.0; break;
        case MAX: e = std::max(e, raw_r); break;
      }
    }
    fused_range_data_.push_back(e);
  }

  return fused_range_data_;
}

bool RangerFusion::checkFusionType(int test_fusion_type)
{
  return (test_fusion_type >=0 && test_fusion_type <= 2)? true : false;
}
int RangerFusion::getFusionType() const
{
  return fusion_type_;
}

void RangerFusion::setFusionType(int fusion_type)
{
  fusion_type_ = fusion_type;
}
