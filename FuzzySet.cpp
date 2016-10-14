#include "FuzzySet.h"


float TrapezoidFuzzySet::membershipFunction(T u)
{
  if (u < this->a || u > this->d)
  {
    return 0;
  }
  if (u >= this->b && u <= this->c)
  {
    return 1;
  }
  if (u < this->b)
  {
    return (u-a)/(b-a);
  }
  return (u-c)/(d-c);
}
