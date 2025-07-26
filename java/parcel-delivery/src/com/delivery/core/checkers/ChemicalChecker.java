package com.delivery.core.checkers;

import com.delivery.common.Parcel;
import com.delivery.core.exceptions.ConditionException;

public class ChemicalChecker extends Checker {
    @Override
    public void check(Parcel parcel) throws ConditionException {
        if (parcel.isChemical()) {
            throw new ConditionException("chemical parcels is not allowed for delivery!");
        }
        checkNext(parcel);
    }
}