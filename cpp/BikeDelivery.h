// =================================================================
// FILE: BikeDelivery.h
// =================================================================
#ifndef BIKE_DELIVERY_H
#define BIKE_DELIVERY_H

#include "DeliveryService.h" 
#include <cmath> // For std::sqrt and std::pow

// BikeDelivery implements the UrbanDeliveryService interface.
class BikeDelivery : public UrbanDeliveryService {
public:
    // Overriding methods from the base interfaces.
    int calculatePrice(const Parcel& parcel) override;
    void checkConditions(const Parcel& parcel) override;
    int calculatePrice(const Parcel& parcel, bool fastDelivery) override;

private:
    // Helper function to calculate Euclidean distance.
    double calculateDistance(const Point& source, const Point& destination);
};

#endif // BIKE_DELIVERY_H
