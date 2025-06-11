// =================================================================
// FILE: DeliveryService.h
// =================================================================
#ifndef DELIVERY_SERVICE_H
#define DELIVERY_SERVICE_H

#include "Parcel.h"

// Base interface for all delivery services.
class DeliveryService {
public:
    virtual ~DeliveryService() = default; // Virtual destructor

    // Pure virtual functions that define the contract for all delivery services.
    virtual int calculatePrice(const Parcel& parcel) = 0;
    virtual void checkConditions(const Parcel& parcel) = 0;
};

// Interface for urban delivery services that support fast delivery.
class UrbanDeliveryService : public virtual DeliveryService {
public:
    virtual ~UrbanDeliveryService() = default;

    // Additional contract for fast delivery option.
    virtual int calculatePrice(const Parcel& parcel, bool fastDelivery) = 0;
};

#endif // DELIVERY_SERVICE_H
