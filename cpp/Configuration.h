// =================================================================
// FILE: Configuration.h
// =================================================================
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// Singleton class to hold global application configuration.
class Configuration {
public:
    // Static method to get the single instance of the class.
    static Configuration& getInstance();

    // Deleting copy constructor and assignment operator to prevent copies.
    Configuration(const Configuration&) = delete;
    void operator=(const Configuration&) = delete;

    // Getters for configuration values.
    int getBasePrice() const;
    int getUnitPrice() const;
    int getWeightLimit() const;
    int getDimensionLimit() const;

private:
    // Private constructor to prevent direct instantiation.
    Configuration();

    int basePrice;
    int unitPrice;
    int weightLimit;
    int dimensionLimit;
};

#endif // CONFIGURATION_H