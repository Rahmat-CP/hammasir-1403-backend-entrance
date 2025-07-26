package com.delivery.core.checkers;

import com.delivery.common.Parcel;
import com.delivery.core.exceptions.ConditionException;

public class FlammableChecker extends Checker {
    @Override
    public void check(Parcel parcel) throws ConditionException {
        if (parcel.isFlammable()) {
            throw new ConditionException("delivery of flammable parcel is not allowed.");
        }
        checkNext(parcel);
    }
}