package com.delivery.core;

import com.delivery.common.Parcel;

public interface IntraCityDeliveryService extends DeliveryService {    /**
     * @param parcel The parcel to be delivered.
     * @param fastDelivery True if fast delivery is requested.
     * @return The calculated price.
     */
    int calculatePrice(Parcel parcel, boolean fastDelivery);
}
