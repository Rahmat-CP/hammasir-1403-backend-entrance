public class ChemicalChecker extends Checker {
    @Override
    public void check(Parcel parcel) throws ConditionException {
        if (parcel.isChemical()) {
            throw new ConditionException("chemical parcels is not allowed for delivery!");
        }
        checkNext(parcel);
    }
}