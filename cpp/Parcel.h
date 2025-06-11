// =================================================================
// FILE: Parcel.h
// =================================================================
#ifndef PARCEL_H
#define PARCEL_H

#include "Point.h"

// Represents a parcel to be delivered.
// Its objects are created using the ParcelBuilder.
class Parcel {
private:
    // The constructor is private to enforce the use of the builder pattern.
    Parcel(int weight, int length, int width, bool isFlammable, bool isChemical, Point source, Point destination, int insurancePrice);

public:
    // Forward declaration of the nested builder class.
    class ParcelBuilder;

    // Static method to get a new builder instance.
    static ParcelBuilder builder();

    // Getters for parcel attributes.
    int getWeight() const;
    int getLength() const;
    int getWidth() const;
    bool getIsFlammable() const;
    bool getIsChemical() const;
    Point getSource() const;
    Point getDestination() const;
    int getInsurancePrice() const;

private:
    int weight;
    int length;
    int width;
    bool isFlammable;
    bool isChemical;
    Point source;
    Point destination;
    int insurancePrice;

public:
    // The nested builder class for constructing Parcel objects.
    class ParcelBuilder {
    public:
        ParcelBuilder();
        ParcelBuilder& weight(int weight);
        ParcelBuilder& length(int length);
        ParcelBuilder& width(int width);
        ParcelBuilder& flammable(bool isFlammable);
        ParcelBuilder& chemical(bool isChemical);
        ParcelBuilder& source(const Point& source);
        ParcelBuilder& destination(const Point& destination);
        ParcelBuilder& insurancePrice(int insurancePrice);
        Parcel build();

    private:
        int m_weight = 0;
        int m_length = 0;
        int m_width = 0;
        bool m_isFlammable = false;
        bool m_isChemical = false;
        Point m_source;
        Point m_destination;
        int m_insurancePrice = 0;
    };
};

#endif // PARCEL_H