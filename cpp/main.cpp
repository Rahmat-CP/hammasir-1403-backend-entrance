// =================================================================
// FILE: main.cpp
// =================================================================
#include <iostream>
#include <memory>
#include "Parcel.h"
#include "BikeDelivery.h"
#include "Configuration.h"

// A helper function to demonstrate a full delivery process for a parcel.
void processDelivery(DeliveryService& service, const Parcel& parcel) {
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "Starting delivery process..." << std::endl;

    // First, check conditions. The function handles its own try-catch.
    service.checkConditions(parcel);

    // In a real app, you would check if an exception was thrown.
    // Here we'll just proceed to show price calculation.
    // Let's assume for demonstration we only calculate price for valid parcels,
    // which we will construct.

    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    // The Configuration singleton is accessed for the first time.
    Configuration& config = Configuration::getInstance();
    std::cout << "System Configuration Loaded:" << std::endl;
    std::cout << " - Base Price: " << config.getBasePrice() << std::endl;
    std::cout << " - Unit Price: " << config.getUnitPrice() << std::endl;
    std::cout << " - Weight Limit: " << config.getWeightLimit() << " kg" << std::endl;

    // Create a delivery service instance.
    BikeDelivery bikeService;

    // --- Test Case 1: A valid parcel ---
    std::cout << "\n--- [Test Case 1: Valid Parcel] ---" << std::endl;
    Point sourcePoint(1, 1);
    Point destPoint(4, 5); // Distance = sqrt((4-1)^2 + (5-1)^2) = sqrt(9+16) = 5
    Parcel validParcel = Parcel::builder()
        .weight(8)
        .length(20)
        .width(30)
        .flammable(false)
        .chemical(false)
        .source(sourcePoint)
        .destination(destPoint)
        .insurancePrice(20000)
        .build();
    
    bikeService.checkConditions(validParcel); // This should pass
    int normalPrice = bikeService.calculatePrice(validParcel);
    int fastPrice = bikeService.calculatePrice(validParcel, true);
    // Expected normal price: (1000 * 5) + 1000 + (0.1 * 20000) = 5000 + 1000 + 2000 = 8000
    // Expected fast price: 8000 + (0.1 * (1000*5)) = 8000 + 500 = 8500
    std::cout << "Standard Delivery Price: " << normalPrice << std::endl;
    std::cout << "Fast Delivery Price: " << fastPrice << std::endl;


    // --- Test Case 2: A parcel that is too heavy ---
    std::cout << "\n--- [Test Case 2: Heavy Parcel] ---" << std::endl;
    Parcel heavyParcel = Parcel::builder()
        .weight(15) // > 10kg limit
        .length(20)
        .width(30)
        .flammable(false)
        .chemical(false)
        .source(sourcePoint)
        .destination(destPoint)
        .insurancePrice(20000)
        .build();
    
    // This will call checkConditions and print the failure message.
    processDelivery(bikeService, heavyParcel);


    // --- Test Case 3: A parcel with flammable content ---
    std::cout << "\n--- [Test Case 3: Flammable Parcel] ---" << std::endl;
    Parcel flammableParcel = Parcel::builder()
        .weight(5)
        .length(20)
        .width(30)
        .flammable(true) // Not allowed
        .chemical(false)
        .source(sourcePoint)
        .destination(destPoint)
        .insurancePrice(20000)
        .build();

    // This will also fail, but earlier in the chain.
    processDelivery(bikeService, flammableParcel);

    return 0;
}