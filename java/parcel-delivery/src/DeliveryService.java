public interface DeliveryService {
    /**
     * @param parcel The parcel to be delivered.
     * @return The calculated price.
     */
    int calculatePrice(Parcel parcel);

    /**
     * @param parcel The parcel to check.
     * @throws ConditionException if any condition is not met.
     */
    void checkConditions(Parcel parcel) throws ConditionException;
}