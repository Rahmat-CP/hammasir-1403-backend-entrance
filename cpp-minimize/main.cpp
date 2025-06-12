#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>

// =================================================================
// 1. Core Data Structures
// =================================================================

// Point struct for coordinates
struct Point {
    int x = 0;
    int y = 0;
};

// Parcel class with a nested Builder
class Parcel {
private:
    // Private constructor to enforce builder usage
    Parcel(int weight, int length, int width, bool isFlammable, bool isChemical, Point source, Point destination, int insurancePrice)
        : weight(weight), length(length), width(width), isFlammable(isFlammable), isChemical(isChemical),
          source(source), destination(destination), insurancePrice(insurancePrice) {}

    int weight;
    int length;
    int width;
    bool isFlammable;
    bool isChemical;
    Point source;
    Point destination;
    int insurancePrice;

public:
    // --- Getters ---
    int getWeight() const { return weight; }
    int getLength() const { return length; }
    int getWidth() const { return width; }
    bool getIsFlammable() const { return isFlammable; }
    bool getIsChemical() const { return isChemical; }
    Point getSource() const { return source; }
    Point getDestination() const { return destination; }
    int getInsurancePrice() const { return insurancePrice; }

    // --- Nested Builder Class ---
    class ParcelBuilder {
    private:
        int m_weight = 0;
        int m_length = 0;
        int m_width = 0;
        bool m_isFlammable = false;
        bool m_isChemical = false;
        Point m_source;
        Point m_destination;
        int m_insurancePrice = 0;

    public:
        ParcelBuilder& weight(int w) { m_weight = w; return *this; }
        ParcelBuilder& length(int l) { m_length = l; return *this; }
        ParcelBuilder& width(int w) { m_width = w; return *this; }
        ParcelBuilder& flammable(bool isFlam) { m_isFlammable = isFlam; return *this; }
        ParcelBuilder& chemical(bool isChem) { m_isChemical = isChem; return *this; }
        ParcelBuilder& source(const Point& s) { m_source = s; return *this; }
        ParcelBuilder& destination(const Point& d) { m_destination = d; return *this; }
        ParcelBuilder& insurancePrice(int price) { m_insurancePrice = price; return *this; }

        Parcel build() {
            return Parcel(m_weight, m_length, m_width, m_isFlammable, m_isChemical, m_source, m_destination, m_insurancePrice);
        }
    };

    // Static method to start the building process
    static ParcelBuilder builder() {
        return ParcelBuilder();
    }
};

// =================================================================
// 2. Configuration (Singleton Pattern)
// =================================================================
class Configuration {
public:
    static Configuration& getInstance() {
        static Configuration instance; // Meyers' Singleton
        return instance;
    }

    // Deleted copy/assignment to prevent multiple instances
    Configuration(const Configuration&) = delete;
    void operator=(const Configuration&) = delete;

    int getBasePrice() const { return basePrice; }
    int getUnitPrice() const { return unitPrice; }
    int getWeightLimit() const { return weightLimit; }
    int getDimensionLimit() const { return dimensionLimit; }

private:
    // Private constructor with default values
    Configuration() 
        : basePrice(1000), unitPrice(1000), weightLimit(10), dimensionLimit(100) {}

    int basePrice;
    int unitPrice;
    int weightLimit;
    int dimensionLimit;
};

// =================================================================
// 3. Framework (Interfaces)
// =================================================================

// Base interface for all delivery services
class DeliveryService {
public:
    virtual ~DeliveryService() = default; // Virtual destructor
    virtual int calculatePrice(const Parcel& parcel) = 0;
    virtual void checkConditions(const Parcel& parcel) = 0;
};

// Interface for urban services with fast delivery
class UrbanDeliveryService : public virtual DeliveryService {
public:
    virtual ~UrbanDeliveryService() = default;
    virtual int calculatePrice(const Parcel& parcel, bool fastDelivery) = 0;
};

// =================================================================
// 4. Condition Checking (Chain of Responsibility Pattern)
// =================================================================

class Checker {
protected:
    Checker* nextChecker = nullptr;
public:
    virtual ~Checker() = default;
    void setNextChecker(Checker* next) { nextChecker = next; }
    virtual void check(const Parcel& parcel) {
        if (nextChecker) {
            nextChecker->check(parcel);
        }
    }
};

class WeightChecker : public Checker {
public:
    void check(const Parcel& parcel) override {
        if (parcel.getWeight() > Configuration::getInstance().getWeightLimit()) {
            std::cout << "Validation Failed: Parcel weight exceeds the limit." << std::endl;
            throw std::runtime_error("Weight check failed.");
        }
        Checker::check(parcel); // Call base to pass to next checker
    }
};

// You can add other checkers like DimensionChecker, FlammableChecker etc.
// For the sake of a minimal example, we'll focus on the requested ones.

// =================================================================
// 5. Concrete Implementation: BikeDelivery
// =================================================================

class BikeDelivery : public UrbanDeliveryService {
private:
    double calculateDistance(const Point& source, const Point& destination) {
        return std::sqrt(std::pow(source.x - destination.x, 2) + std::pow(source.y - destination.y, 2));
    }

public:
    void checkConditions(const Parcel& parcel) override {
        std::cout << "Checking parcel conditions for Bike Delivery..." << std::endl;
        WeightChecker weightChecker;
        // In a real scenario, you would chain more checkers here.
        // For example:
        // DimensionChecker dimensionChecker;
        // weightChecker.setNextChecker(&dimensionChecker);
        
        try {
            weightChecker.check(parcel);
            std::cout << "All conditions met. Parcel is valid." << std::endl;
        } catch (const std::runtime_error& e) {
            // Error message is already printed by the specific checker.
        }
    }

    int calculatePrice(const Parcel& parcel) override {
        return calculatePrice(parcel, false); // Default to standard delivery
    }

    int calculatePrice(const Parcel& parcel, bool fastDelivery) override {
        Configuration& config = Configuration::getInstance();
        double distance = calculateDistance(parcel.getSource(), parcel.getDestination());

        double price = (config.getUnitPrice() * distance) 
                     + config.getBasePrice() 
                     + (0.10 * parcel.getInsurancePrice());

        if (fastDelivery) {
            price += 0.10 * (config.getUnitPrice() * distance);
        }
        return static_cast<int>(price);
    }
};


// =================================================================
// 6. Main Program
// =================================================================
int main() {
    // --- Test Case 1: A valid parcel ---
    std::cout << "--- [Test Case 1: Valid Parcel] ---" << std::endl;
    Parcel validParcel = Parcel::builder()
        .weight(8) // within 10kg limit
        .length(20).width(30)
        .source({1, 1}).destination({4, 5}) // distance = 5
        .insurancePrice(10000)
        .build();

    BikeDelivery bikeService;
    bikeService.checkConditions(validParcel);

    int normalPrice = bikeService.calculatePrice(validParcel);
    int fastPrice = bikeService.calculatePrice(validParcel, true);
    // Expected normal: (1000 * 5) + 1000 + (0.1 * 10000) = 5000 + 1000 + 1000 = 7000
    // Expected fast: 7000 + 0.1 * (1000 * 5) = 7000 + 500 = 7500
    std::cout << "Standard Delivery Price: " << normalPrice << std::endl;
    std::cout << "Fast Delivery Price: " << fastPrice << std::endl;

    std::cout << "\n--- [Test Case 2: Heavy Parcel] ---" << std::endl;
    Parcel heavyParcel = Parcel::builder()
        .weight(12) // exceeds 10kg limit
        .source({1, 1}).destination({4, 5})
        .build();
    
    bikeService.checkConditions(heavyParcel);

    return 0;
}
