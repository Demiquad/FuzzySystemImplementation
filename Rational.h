#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
  public:
    Rational();
    Rational(const Rational&);
    Rational(int, int d = 1);

    Rational operator+ (const Rational& rhs) const;
    Rational operator- () const;
    Rational operator- (const Rational& rhs) const;
    Rational operator* (const Rational& rhs) const;
    Rational operator/ (const Rational& rhs) const;

    bool operator< (const Rational& rhs) const;
    bool operator<= (const Rational& rhs) const;
    bool operator> (const Rational& rhs) const;
    bool operator>= (const Rational& rhs) const;
    bool operator== (const Rational& rhs) const;
    bool operator!= (const Rational& rhs) const;

    operator float () const;
    
    friend std::ostream& operator<< (std::ostream&, const Rational&);
  private:
    int num;
    unsigned int den;
    static unsigned int gcd(unsigned int, unsigned int);
    static unsigned int lcm(unsigned int, unsigned int);
    void simplify();
  protected:
};
#endif //RATIONAL_H
