import math
from point import Point
from parcel import Parcel
from framework import UrbanDeliveryService
from checkers import FlammableChecker, DimensionChecker, WeightChecker
from configuration import Configuration

class BikeDelivery(UrbanDeliveryService):
    def _calculate_distance(self, source: Point, destination: Point) -> float:
        return math.sqrt((source.x - destination.x)**2 + (source.y - destination.y)**2)

    def check_conditions(self, parcel: Parcel) -> None:
        """Builds the chain of checkers and initiates the validation."""
        print("Checking parcel conditions for Bike Delivery...")
        
        flammable_checker = FlammableChecker()
        dimension_checker = DimensionChecker()
        weight_checker = WeightChecker()
        
        flammable_checker.set_next_checker(dimension_checker).set_next_checker(weight_checker)
        
        try:
            flammable_checker.check(parcel)
            print("All conditions met. Parcel is valid for bike delivery.")
        except ValueError:
            pass

    def calculate_price(self, parcel: Parcel, fast_delivery: bool = False) -> int:
        """Calculates price for bike delivery, with an option for fast delivery."""
        config = Configuration.get_instance()
        distance = self._calculate_distance(parcel.source, parcel.destination)
        price = (config.unit_price * distance) + config.base_price + (0.10 * parcel.insurance_price)
        if fast_delivery:
            price += 0.10 * (config.unit_price * distance)
        return int(price)