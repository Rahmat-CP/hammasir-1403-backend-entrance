// =================================================================
// FILE: Configuration.cpp
// =================================================================
#include "Configuration.h"

// The private constructor initializes the configuration values.
// These values are loaded once when getInstance() is first called.
Configuration::Configuration()
{
    basePrice = 1000;
    unitPrice = 1000;
    weightLimit = 10;     // 10 kg
    dimensionLimit = 100; // Example: 100 cm for sum of length and width
}

// The Meyers' Singleton implementation.
// The instance is created on first access and is thread-safe in C++11+.
Configuration &Configuration::getInstance()
{
    static Configuration instance;
    return instance;
}

int Configuration::getBasePrice() const { return basePrice; }
int Configuration::getUnitPrice() const { return unitPrice; }
int Configuration::getWeightLimit() const { return weightLimit; }
int Configuration::getDimensionLimit() const { return dimensionLimit; }