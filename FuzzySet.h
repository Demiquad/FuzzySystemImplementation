#ifndef FUZZYSET_H
#define FUZZYSET_H
#include <string>

template <typename T> class AndFuzzySet;
template <typename T> class OrFuzzySet;
template <typename T> class NotFuzzySet;

template <typename T> class FuzzySet
{
  public:
    std::string label;
    virtual double membershipFunction(const T& value) const = 0;
    AndFuzzySet<T> operator&& (const FuzzySet<T>&) const;
    OrFuzzySet<T> operator|| (const FuzzySet<T>&) const;
    NotFuzzySet<T> operator! () const;
  private:
  protected:
};

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

template <typename T> class AndFuzzySet : public FuzzySet<T>
{
  public:
    AndFuzzySet(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs);
    const FuzzySet<T>& lhs;
    const FuzzySet<T>& rhs;
    double membershipFunction(const T& value) const;
};

template <typename T> class OrFuzzySet : public FuzzySet<T>
{
  public:
    OrFuzzySet(const FuzzySet<T>& lhs, const FuzzySet<T>& rhs);
    const FuzzySet<T>& lhs;
    const FuzzySet<T>& rhs;
    double membershipFunction(const T& value) const;
};

template <typename T> class NotFuzzySet : public FuzzySet<T>
{
  public:
    NotFuzzySet(const FuzzySet<T>& lhs);
    const FuzzySet<T>& lhs;
    double membershipFunction(const T& value) const;
};

#include "FuzzySet.cpp"

#endif //FUZZYSET_H
