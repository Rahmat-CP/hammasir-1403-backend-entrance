public class DimensionChecker extends Checker {
    @Override
    public void check(Parcel parcel) throws ConditionException {
        Configuration config = Configuration.getInstance();
        int totalDimensions = parcel.getLength() + parcel.getWidth();
        if (totalDimensions > config.getDimensionLimit()) {
            throw new ConditionException("dimension of this parcel is invalid, maximum dimension is " + config.getDimensionLimit());
        }
        checkNext(parcel);
    }
}