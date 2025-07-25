public final class Configuration {

    private static final Configuration INSTANCE = new Configuration();

    private final int basePrice;
    private final int unitPrice;
    private final int weightLimit;
    private final int dimensionLimit;

    private Configuration() {
        this.basePrice = 1000;
        this.unitPrice = 1000;
        this.weightLimit = 10; // 10 kg
        this.dimensionLimit = 100;
    }

    /**
     * @return The single instance of Configuration.
     */
    public static Configuration getInstance() {
        return INSTANCE;
    }

    // متدهای Getter برای دسترسی به مقادیر تنظیمات
    public int getBasePrice() { return basePrice; }
    public int getUnitPrice() { return unitPrice; }
    public int getWeightLimit() { return weightLimit; }
    public int getDimensionLimit() { return dimensionLimit; }
}