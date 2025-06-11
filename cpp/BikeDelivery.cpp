// =================================================================
// FILE: BikeDelivery.cpp
// =================================================================
#include "BikeDelivery.h"
#include "Configuration.h"
#include "Checker.h"
#include <iostream>
#include <stdexcept>

// Calculates the Euclidean distance between two points.
double BikeDelivery::calculateDistance(const Point& source, const Point& destination) {
    double dx = source.x - destination.x;
    double dy = source.y - destination.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Implements price calculation for BikeDelivery.
int BikeDelivery::calculatePrice(const Parcel& parcel, bool fastDelivery) {
    Configuration& config = Configuration::getInstance();
    double distance = calculateDistance(parcel.getSource(), parcel.getDestination());

    // Base price calculation
    double price = (config.getUnitPrice() * distance) 
                 + config.getBasePrice() 
                 + (0.10 * parcel.getInsurancePrice());

    // Add surcharge for fast delivery
    if (fastDelivery) {
        price += 0.10 * (config.getUnitPrice() * distance);
    }

    return static_cast<int>(price);
}

// Implements the base version of calculatePrice, defaulting to standard delivery.
int BikeDelivery::calculatePrice(const Parcel& parcel) {
    return calculatePrice(parcel, false);
}

// Implements condition checking using a specific chain of checkers for bike delivery.
void BikeDelivery::checkConditions(const Parcel& parcel) {
    std::cout << "Checking parcel conditions for Bike Delivery..." << std::endl;

    // For BikeDelivery, the check order is defined here:
    // 1. Not flammable -> 2. Not chemical -> 3. Weight -> 4. Dimensions
    FlammableChecker flammableChecker;
    ChemicalChecker chemicalChecker;
    WeightChecker weightChecker;
    DimensionChecker dimensionChecker;

    // Build the chain of responsibility.
    flammableChecker.setNextChecker(&chemicalChecker);
    chemicalChecker.setNextChecker(&weightChecker);
    weightChecker.setNextChecker(&dimensionChecker);

    try {
        // Start the validation from the first checker in the chain.
        flammableChecker.check(parcel);
        std::cout << "All conditions met. Parcel is valid for bike delivery." << std::endl;
    } catch (const std::runtime_error& e) {
        // The process stops here. The error message is already printed by the specific checker.
        // We catch the exception to prevent the program from crashing.
    }
}