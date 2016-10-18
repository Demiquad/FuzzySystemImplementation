#include <iostream>
#include "FuzzySet.h"

 
int main()
{
  double a,b,c,d,e,f,g,h;
  
  a = 1.2;
  b = 3.0;
  c = 3.4;
  d = 3.9;

  e = 2.0;
  f = 3.0;
  g = 3.5;
  h = 3.7;
  
  
  TrapezoidFuzzySet <double> FS1(a,b,c,d);
  TrapezoidFuzzySet <double> FS2(e,f,g,h);
  
  for(double i = 1.0; i < 4.0; i += 0.05)
  {
    std::cout << "u1 = " << i << " : " << FS1.membershipFunction(i) << std::endl;
  }

  for(double i = 1.0; i < 4.0; i += 0.05)
  {
    std::cout << "u2 = " << i << " : " << FS2.membershipFunction(i) << std::endl;
  }

  AndFuzzySet <double> ANDFS = FS1&&FS2;
  
  for(double i = 1.0; i < 4.0; i += 0.05)
  {
    std::cout << "uAND = " << i << " : " << ANDFS.membershipFunction(i) << std::endl;
  }

  OrFuzzySet <double> ORFS = FS1||FS2;
  
  for(double i = 1.0; i < 4.0; i += 0.05)
  {
    std::cout << "uOR = " << i << " : " << ORFS.membershipFunction(i) << std::endl;
  }

  NotFuzzySet <double> N1(FS1), N2(FS2);
  OrFuzzySet <double> NOR(N1, N2);
  NotFuzzySet <double> NOTFS = !NOR;
  for (double i = 1.0; i < 4.0; i += 0.05)
  {
    double pippo = NOTFS.membershipFunction(i);
    double pluto = ANDFS.membershipFunction(i);
    std::cout << "u = " << i << " : " << pippo << " , " << pluto << " => " << (pippo == pluto?"OK":"OOOPS") << std::endl;
  }  
  
  
  return 0;
}
