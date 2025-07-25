public class BikeDelivery implements IntraCityDeliveryService {

    private final Configuration config;

    public BikeDelivery() {
        this.config = Configuration.getInstance();
    }

    @Override
    public int calculatePrice(Parcel parcel) {
        return calculatePrice(parcel, false);
    }

    @Override
    public int calculatePrice(Parcel parcel, boolean fastDelivery) {
        Point source = parcel.getSource();
        Point destination = parcel.getDestination();
        double distance = source.distanceTo(destination);

        double price = (config.getUnitPrice() * distance) + config.getBasePrice() + (0.10 * parcel.getInsurancePrice());

        if (fastDelivery) {
            price += 0.10 * (config.getUnitPrice() * distance);
        }

        return (int) Math.round(price);
    }

    @Override
    public void checkConditions(Parcel parcel) throws ConditionException {
        Checker weightChecker = new WeightChecker();
        Checker dimensionChecker = new DimensionChecker();
        Checker flammableChecker = new FlammableChecker();
        Checker chemicalChecker = new ChemicalChecker();

        weightChecker.setNextChecker(dimensionChecker);
        dimensionChecker.setNextChecker(flammableChecker);
        flammableChecker.setNextChecker(chemicalChecker);

        weightChecker.check(parcel);
    }
}