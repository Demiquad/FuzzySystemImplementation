#include <iostream>
#include "FuzzySet.h"
 
int main()
{
  float a,b,c,d;
  a = 2.0;
  b = 3.0;
  c = 3.3;
  d = 3.3;
  
  TrapezoidFuzzySet <float> FS1(a,b,c,d);
  FS1.membershipFunction(3.2);
  return 0;
}
