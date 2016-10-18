#ifndef FUZZYSET_H
#define FUZZYSET_H
#include <string>

template <typename T> class IntersectionFuzzySet;
template <typename T> class UnionFuzzy;
template <typename T> class ComplementFuzzy;

// ABSTRACT FUZZYSET class prototype
template <typename T> class FuzzySet
{
  public:
    std::string label;
    virtual double membershipFunction(const T& value) const = 0;
    IntersectionFuzzySet<T> operator* (const FuzzySet<T>&) const;
    UnionFuzzy<T> operator+ (const FuzzySet<T>&) const;
    ComplementFuzzy<T> operator! () const;
  private:
  protected:
};

// TRAPEZOID FUZZYSET class prototype
template <typename T> class TrapezoidFuzzySet : public FuzzySet<T>
{
  public:
    TrapezoidFuzzySet(const T& a, const T& b, const T& c, const T& d);
    T a;
    T b;
    T c;
    T d;
    double membershipFunction(const T& value) const;
  private:
  protected:
};

// AND FUZZYSET class prototype
template <typename T> class IntersectionFuzzySet : public FuzzySet<T>
{
  public:
    IntersectionFuzzySet(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs);
    const FuzzySet<T>& lhs;
    const FuzzySet<T>& rhs;
    double membershipFunction(const T& value) const;
};

// OR FUZZYSET class prototype
template <typename T> class UnionFuzzy : public FuzzySet<T>
{
  public:
    UnionFuzzy(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs);
    const FuzzySet<T>& lhs;
    const FuzzySet<T>& rhs;
    double membershipFunction(const T& value) const;
};

// NOT FUZZYSET class prototype
template <typename T> class ComplementFuzzy : public FuzzySet<T>
{
  public:
    ComplementFuzzy(const FuzzySet<T>& lhs);
    const FuzzySet<T>& lhs;
    double membershipFunction(const T& value) const;
};

#include "FuzzySet.cpp"

#endif //FUZZYSET_H
