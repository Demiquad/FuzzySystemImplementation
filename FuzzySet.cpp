#include "FuzzySet.h"

// ABSTRACT FUZZYSET implementation
template <typename T> TrapezoidFuzzySet<T>::TrapezoidFuzzySet(const T& a, const T& b, const T& c, const T& d) : a(a), b(b), c(c), d(d) {}

// TRAPEZOID FUZZYSET implementation
template <typename T> double TrapezoidFuzzySet<T>::membershipFunction(const T& u) const
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
  return (d-u)/(d-c);
}

// AND implementation
template <typename T> AndFuzzySet<T> FuzzySet<T>::operator* (const FuzzySet<T>& rhs) const
{
  return AndFuzzySet<T>(*this, rhs);
}

template <typename T> AndFuzzySet<T>::AndFuzzySet(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs) : lhs(lhs), rhs(rhs) {}

template <typename T> double AndFuzzySet<T>::membershipFunction(const T& u) const
{
  double v1 = this->lhs.membershipFunction(u);
  double v2 = this->rhs.membershipFunction(u);
  return v1<v2?v1:v2;
}

// OR implementation
template <typename T> OrFuzzySet<T> FuzzySet<T>::operator+ (const FuzzySet<T>& rhs) const
{
  return OrFuzzySet<T>(*this, rhs);
}

template <typename T> OrFuzzySet<T>::OrFuzzySet(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs) : lhs(lhs), rhs(rhs) {}

template <typename T> double OrFuzzySet<T>::membershipFunction(const T& u) const
{
  double v1 = this->lhs.membershipFunction(u);
  double v2 = this->rhs.membershipFunction(u);
  return v1>v2?v1:v2;
}

// NOT implementation
template <typename T> NotFuzzySet<T> FuzzySet<T>::operator! () const
{
  return NotFuzzySet<T>(*this);
}

template <typename T> NotFuzzySet<T>::NotFuzzySet(const FuzzySet<T>& lhs) : lhs(lhs) {}

template <typename T> double NotFuzzySet<T>::membershipFunction(const T& u) const
{
  return 1 - this->lhs.membershipFunction(u);
}

