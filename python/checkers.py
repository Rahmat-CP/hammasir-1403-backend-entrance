from abc import ABC, abstractmethod
from parcel import Parcel
from configuration import Configuration

class Checker(ABC):
    """Abstract base class for a handler in the chain of responsibility."""
    def __init__(self):
        self._next_checker: 'Checker' | None = None

    def set_next_checker(self, next_checker: 'Checker') -> 'Checker':
        self._next_checker = next_checker
        return next_checker

    @abstractmethod
    def check(self, parcel: Parcel) -> None:
        pass

class WeightChecker(Checker):
    def check(self, parcel: Parcel) -> None:
        config = Configuration.get_instance()
        if parcel.weight > config.weight_limit:
            print(f"Validation Failed: Parcel weight {parcel.weight}kg exceeds the limit of {config.weight_limit}kg.")
            raise ValueError("Weight check failed.")
        
        if self._next_checker:
            self._next_checker.check(parcel)

class DimensionChecker(Checker):
    def check(self, parcel: Parcel) -> None:
        config = Configuration.get_instance()
        if (parcel.length + parcel.width) > config.dimension_limit:
            print("Validation Failed: Parcel dimensions exceed the allowed limit.")
            raise ValueError("Dimension check failed.")

        if self._next_checker:
            self._next_checker.check(parcel)

class FlammableChecker(Checker):
    def check(self, parcel: Parcel) -> None:
        if parcel.is_flammable:
            print("Validation Failed: Flammable items are not allowed.")
            raise ValueError("Flammable check failed.")

        if self._next_checker:
            self._next_checker.check(parcel)