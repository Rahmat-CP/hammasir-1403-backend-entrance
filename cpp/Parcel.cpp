
// =================================================================
// FILE: Parcel.cpp
// =================================================================
#include "Parcel.h"

// --- Parcel Implementation ---
Parcel::Parcel(int weight, int length, int width, bool isFlammable, bool isChemical, Point source, Point destination, int insurancePrice)
    : weight(weight), length(length), width(width), isFlammable(isFlammable), isChemical(isChemical),
      source(source), destination(destination), insurancePrice(insurancePrice) {}

Parcel::ParcelBuilder Parcel::builder() {
    return ParcelBuilder();
}

int Parcel::getWeight() const { return weight; }
int Parcel::getLength() const { return length; }
int Parcel::getWidth() const { return width; }
bool Parcel::getIsFlammable() const { return isFlammable; }
bool Parcel::getIsChemical() const { return isChemical; }
Point Parcel::getSource() const { return source; }
Point Parcel::getDestination() const { return destination; }
int Parcel::getInsurancePrice() const { return insurancePrice; }

// --- ParcelBuilder Implementation ---
Parcel::ParcelBuilder::ParcelBuilder() {}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::weight(int weight) {
    m_weight = weight;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::length(int length) {
    m_length = length;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::width(int width) {
    m_width = width;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::flammable(bool isFlammable) {
    m_isFlammable = isFlammable;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::chemical(bool isChemical) {
    m_isChemical = isChemical;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::source(const Point& source) {
    m_source = source;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::destination(const Point& destination) {
    m_destination = destination;
    return *this;
}

Parcel::ParcelBuilder& Parcel::ParcelBuilder::insurancePrice(int insurancePrice) {
    m_insurancePrice = insurancePrice;
    return *this;
}

Parcel Parcel::ParcelBuilder::build() {
    // We can call the private constructor of Parcel here because ParcelBuilder is a nested class.
    return Parcel(m_weight, m_length, m_width, m_isFlammable, m_isChemical, m_source, m_destination, m_insurancePrice);
}
