// =================================================================
// FILE: Checker.cpp
// =================================================================
#include "Checker.h"
#include "Configuration.h"
#include <iostream>
#include <stdexcept>

void Checker::setNextChecker(Checker* next) {
    nextChecker = next;
}

// --- WeightChecker Implementation ---
void WeightChecker::check(const Parcel& parcel) {
    int weightLimit = Configuration::getInstance().getWeightLimit();
    if (parcel.getWeight() > weightLimit) {
        // Condition failed. Print a message and throw an exception to stop the chain.
        std::cout << "Validation Failed: Parcel weight exceeds the limit of " << weightLimit << " kg." << std::endl;
        throw std::runtime_error("Weight check failed.");
    }

    // If condition is met, pass to the next checker in the chain.
    if (nextChecker != nullptr) {
        nextChecker->check(parcel);
    }
}

// --- DimensionChecker Implementation ---
void DimensionChecker::check(const Parcel& parcel) {
    int dimensionLimit = Configuration::getInstance().getDimensionLimit();
    // Assuming dimension limit is the sum of length and width for a bike courier.
    if ((parcel.getLength() + parcel.getWidth()) > dimensionLimit) {
        std::cout << "Validation Failed: Parcel dimensions exceed the allowed limit." << std::endl;
        throw std::runtime_error("Dimension check failed.");
    }
    if (nextChecker != nullptr) {
        nextChecker->check(parcel);
    }
}

// --- FlammableChecker Implementation ---
void FlammableChecker::check(const Parcel& parcel) {
    if (parcel.getIsFlammable()) {
        std::cout << "Validation Failed: Flammable items are not allowed for this delivery type." << std::endl;
        throw std::runtime_error("Flammable check failed.");
    }
    if (nextChecker != nullptr) {
        nextChecker->check(parcel);
    }
}

// --- ChemicalChecker Implementation ---
void ChemicalChecker::check(const Parcel& parcel) {
    if (parcel.getIsChemical()) {
        std::cout << "Validation Failed: Chemical items are not allowed for this delivery type." << std::endl;
        throw std::runtime_error("Chemical check failed.");
    }
    if (nextChecker != nullptr) {
        nextChecker->check(parcel);
    }
}
