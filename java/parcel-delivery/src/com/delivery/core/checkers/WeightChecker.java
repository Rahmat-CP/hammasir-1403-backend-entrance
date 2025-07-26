package com.delivery.core.checkers;

import com.delivery.common.Parcel;
import com.delivery.config.Configuration;
import com.delivery.core.exceptions.ConditionException;

public class WeightChecker extends Checker {
    @Override
    public void check(Parcel parcel) throws ConditionException {
        Configuration config = Configuration.getInstance();
        if (parcel.getWeight() > config.getWeightLimit()) {
            throw new ConditionException("weight of this parcel is invalid, maximum weight is " + config.getWeightLimit() + " kg");
        }

        checkNext(parcel);
    }
}