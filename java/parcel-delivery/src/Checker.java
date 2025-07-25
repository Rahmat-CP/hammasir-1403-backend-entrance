public abstract class Checker {
    protected Checker nextChecker;

    /**
     * @param nextChecker The next checker in the chain.
     */
    public void setNextChecker(Checker nextChecker) {
        this.nextChecker = nextChecker;
    }

    /**
     * @param parcel The parcel to check.
     * @throws ConditionException if the condition is not met.
     */
    public abstract void check(Parcel parcel) throws ConditionException;

    /**
     * @param parcel The parcel to be checked by the next checker.
     * @throws ConditionException if a subsequent check fails.
     */
    protected void checkNext(Parcel parcel) throws ConditionException {
        if (nextChecker != null) {
            nextChecker.check(parcel);
        }
    }
}
