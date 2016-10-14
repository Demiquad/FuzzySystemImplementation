#ifndef FUZZYSET_H
#define FUZZYSET_H
#include <string>

template <typename T> class FuzzySet
{
  public:
    std::string label;
    virtual float membershipFunction(T value);
  private:
  protected:
};

template <typename T> class TrapezoidFuzzySet : FuzzySet<T>
{
  public:
    TrapezoidFuzzySet(T a, T b, T c, T d);
    T a;
    T b;
    T c;
    T d;
    float membershipFunction(T value);
  private:
  protected:
};

#endif //FUZZYSET_H
