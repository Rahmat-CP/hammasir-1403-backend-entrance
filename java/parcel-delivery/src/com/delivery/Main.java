package com.delivery;

import com.delivery.common.Parcel;
import com.delivery.common.Point;
import com.delivery.core.IntraCityDeliveryService;
import com.delivery.core.exceptions.ConditionException;
import com.delivery.services.BikeDelivery;

public class Main {
    public static void main(String[] args) {
        System.out.println("--- testing program ---");

        IntraCityDeliveryService bikeDelivery = new BikeDelivery();

        var sourcePoint = new Point(10, 10);
        var destinationPoint = new Point(40, 50);

        System.out.println("\n1. valid parcel");
        Parcel validParcel = Parcel.builder()
                .weight(8) // less than 10 kg
                .length(30)
                .width(20) // less than 100
                .isFlammable(false)
                .isChemical(false)
                .source(sourcePoint)
                .destination(destinationPoint)
                .insurancePrice(10000)
                .build();

        try {
            System.out.println("check conditions ...");
            bikeDelivery.checkConditions(validParcel);
            System.out.println("conditions are approved!");

            int normalPrice = bikeDelivery.calculatePrice(validParcel, false);
            System.out.println("normal price is: " + normalPrice);

            int fastPrice = bikeDelivery.calculatePrice(validParcel, true);
            System.out.println("fast delivery price is: " + fastPrice);

        } catch (ConditionException e) {
            System.err.println("we have some issues: " + e.getMessage());
        }

        System.out.println("\n2. invalid parcel - out of range weight ...");
        Parcel heavyParcel = Parcel.builder()
                .weight(15) // more than 10 kg
                .length(30)
                .width(20)
                .isFlammable(false)
                .isChemical(false)
                .source(sourcePoint)
                .destination(destinationPoint)
                .insurancePrice(10000)
                .build();

        try {
            System.out.println("check conditions ...");
            bikeDelivery.checkConditions(heavyParcel);
        } catch (ConditionException e) {
            System.out.println("conditions are not approved: " + e.getMessage());
        }

        System.out.println("\n3. invalid parcel - flameable parcel ...");
        Parcel flammableParcel = Parcel.builder()
                .weight(5)
                .length(10)
                .width(10)
                .isFlammable(true) // invalid
                .isChemical(false)
                .source(sourcePoint)
                .destination(destinationPoint)
                .insurancePrice(50000)
                .build();

        try {
            System.out.println("check conditions ...");
            bikeDelivery.checkConditions(flammableParcel);
        } catch (ConditionException e) {
            System.out.println("conditions are not approved: " + e.getMessage());
        }

        System.out.println("\n--- program ended successfully ---");
    }
}