from point import Point

class Parcel:
    """Represents a parcel to be delivered.
    Objects of this class should be created using the nested ParcelBuilder.
    """
    class ParcelBuilder:
        """The nested builder class for fluently constructing a Parcel object."""
        def __init__(self):
            self._weight = 0
            self._length = 0
            self._width = 0
            self._is_flammable = False
            self._is_chemical = False
            self._source = Point(0, 0)
            self._destination = Point(0, 0)
            self._insurance_price = 0

        def weight(self, weight: int) -> 'Parcel.ParcelBuilder':
            self._weight = weight
            return self

        def length(self, length: int) -> 'Parcel.ParcelBuilder':
            self._length = length
            return self

        def width(self, width: int) -> 'Parcel.ParcelBuilder':
            self._width = width
            return self

        def flammable(self, is_flammable: bool) -> 'Parcel.ParcelBuilder':
            self._is_flammable = is_flammable
            return self

        def chemical(self, is_chemical: bool) -> 'Parcel.ParcelBuilder':
            self._is_chemical = is_chemical
            return self

        def source(self, source: Point) -> 'Parcel.ParcelBuilder':
            self._source = source
            return self

        def destination(self, destination: Point) -> 'Parcel.ParcelBuilder':
            self._destination = destination
            return self
        
        def insurance_price(self, price: int) -> 'Parcel.ParcelBuilder':
            self._insurance_price = price
            return self

        def build(self) -> 'Parcel':
            """Creates the final Parcel object from the builder's state."""
            return Parcel(
                self._weight, self._length, self._width, self._is_flammable,
                self._is_chemical, self._source, self._destination, self._insurance_price
            )

    def __init__(self, weight, length, width, is_flammable, is_chemical, source, destination, insurance_price):
        self._weight = weight
        self._length = length
        self._width = width
        self._is_flammable = is_flammable
        self._is_chemical = is_chemical
        self._source = source
        self._destination = destination
        self._insurance_price = insurance_price

    @staticmethod
    def builder() -> 'Parcel.ParcelBuilder':
        """Static method to get a new builder instance."""
        return Parcel.ParcelBuilder()

    @property
    def weight(self) -> int: return self._weight
    @property
    def length(self) -> int: return self._length
    @property
    def width(self) -> int: return self._width
    @property
    def is_flammable(self) -> bool: return self._is_flammable
    @property
    def is_chemical(self) -> bool: return self._is_chemical
    @property
    def source(self) -> Point: return self._source
    @property
    def destination(self) -> Point: return self._destination
    @property
    def insurance_price(self) -> int: return self._insurance_price