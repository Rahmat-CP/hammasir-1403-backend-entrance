public final class Parcel {
    private final int weight;
    private final int length;
    private final int width;
    private final boolean isFlammable;
    private final boolean isChemical;
    private final Point source;
    private final Point destination;
    private final int insurancePrice;

    private Parcel(ParcelBuilder builder) {
        this.weight = builder.weight;
        this.length = builder.length;
        this.width = builder.width;
        this.isFlammable = builder.isFlammable;
        this.isChemical = builder.isChemical;
        this.source = builder.source;
        this.destination = builder.destination;
        this.insurancePrice = builder.insurancePrice;
    }


    public int getWeight() {
        return weight;
    }

    public int getLength() {
        return length;
    }

    public int getWidth() {
        return width;
    }

    public boolean isFlammable() {
        return isFlammable;
    }

    public boolean isChemical() {
        return isChemical;
    }

    public Point getSource() {
        return source;
    }

    public Point getDestination() {
        return destination;
    }

    public int getInsurancePrice() {
        return insurancePrice;
    }

    /**
     * @return A new instance of ParcelBuilder.
     */
    public static ParcelBuilder builder() {
        return new ParcelBuilder();
    }

    public static class ParcelBuilder {
        private int weight;
        private int length;
        private int width;
        private boolean isFlammable;
        private boolean isChemical;
        private Point source;
        private Point destination;
        private int insurancePrice;

        private ParcelBuilder() {
        }

        public ParcelBuilder weight(int weight) {
            this.weight = weight;
            return this;
        }

        public ParcelBuilder length(int length) {
            this.length = length;
            return this;
        }

        public ParcelBuilder width(int width) {
            this.width = width;
            return this;
        }

        public ParcelBuilder isFlammable(boolean isFlammable) {
            this.isFlammable = isFlammable;
            return this;
        }

        public ParcelBuilder isChemical(boolean isChemical) {
            this.isChemical = isChemical;
            return this;
        }

        public ParcelBuilder source(Point source) {
            this.source = source;
            return this;
        }

        public ParcelBuilder destination(Point destination) {
            this.destination = destination;
            return this;
        }

        public ParcelBuilder insurancePrice(int insurancePrice) {
            this.insurancePrice = insurancePrice;
            return this;
        }

        /**
         * @return A new Parcel object.
         */
        public Parcel build() {
            // validations can write here
            return new Parcel(this);
        }
    }
}
