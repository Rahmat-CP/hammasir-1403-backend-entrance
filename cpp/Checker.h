// =================================================================
// FILE: Checker.h
// =================================================================
#ifndef CHECKER_H
#define CHECKER_H

#include "Parcel.h"

// Abstract base class for the checkers in the chain of responsibility.
class Checker {
public:
    virtual ~Checker() = default;

    // Sets the next checker in the chain.
    void setNextChecker(Checker* next);
    
    // Abstract method to perform the check. Throws an exception on failure.
    virtual void check(const Parcel& parcel) = 0;

protected:
    Checker* nextChecker = nullptr;
};

// Concrete checker for parcel weight.
class WeightChecker : public Checker {
public:
    void check(const Parcel& parcel) override;
};

// Concrete checker for parcel dimensions.
class DimensionChecker : public Checker {
public:
    void check(const Parcel& parcel) override;
};

// Concrete checker for flammable items.
class FlammableChecker : public Checker {
public:
    void check(const Parcel& parcel) override;
};

// Concrete checker for chemical items.
class ChemicalChecker : public Checker {
public:
    void check(const Parcel& parcel) override;
};

#endif // CHECKER_H