#include "Rational.h"

Rational::Rational()
{
  this->num = 0;
  this->den = 1;
}

Rational::Rational(const Rational& other)
{
  this->num = other.num;
  this->den = other.den;
}

Rational::Rational(int n, int d)
{
  this->num = (d<0?-1:1)*n;
  this->den = (d<0?-1:1)*d;
  this->simplify();
}

Rational Rational::operator+ (const Rational& rhs) const
{
  return Rational(
    this->num*rhs.den+this->den*rhs.num,
    this->den*rhs.den
  );
}

Rational Rational::operator- () const
{
  return Rational(-this->num, this->den);
}

Rational Rational::operator- (const Rational& rhs) const
{
  return *this + (-rhs);
}

Rational Rational::operator* (const Rational& rhs) const
{
  return Rational(this->num*rhs.num, this->den*rhs.den);
}

Rational Rational::operator/ (const Rational& rhs) const
{
  return Rational(this->num*rhs.den, this->den*rhs.num);
}

bool Rational::operator< (const Rational& rhs) const
{
  return this->num*rhs.den < this->den*rhs.num;
}

bool Rational::operator<= (const Rational& rhs) const
{
  return !(*this>rhs);
}

bool Rational::operator> (const Rational& rhs) const
{
  return rhs<*this;
}

bool Rational::operator>= (const Rational& rhs) const
{
  return !(*this<rhs);
}

bool Rational::operator== (const Rational& rhs) const
{
  return this->num==rhs.num && this->den==rhs.den;
}

bool Rational::operator!= (const Rational& rhs) const
{
  return !(*this == rhs);
}

Rational::operator float () const
{
  return (float) this->num/this->den;
}

unsigned int Rational::gcd(unsigned int a, unsigned int b)
{
  while (b)
  {
    a %= b;
    if (!a) return b;
    b %= a;
  }
  return a;
}

unsigned int Rational::lcm(unsigned int a, unsigned int b)
{
  return a*b/gcd(a,b);
}

void Rational::simplify()
{
  unsigned int d = gcd(this->num>0?this->num:-this->num, this->den);
  this->num /= d;
  this->den /= d;
}

std::ostream& operator<< (std::ostream& os, const Rational& r)
{
  return os << r.num << "/" << r.den;
}
