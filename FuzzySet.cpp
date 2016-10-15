#include "FuzzySet.h"

template <typename T> TrapezoidFuzzySet<T>::TrapezoidFuzzySet(T a, T b, T c, T d)
: a(a), b(b), c(c), d(d) {}


template <typename T> float TrapezoidFuzzySet<T>::membershipFunction(T u)
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
