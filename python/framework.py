from abc import ABC, abstractmethod
from parcel import Parcel

class DeliveryService(ABC):
    """Base interface (Abstract Base Class) for all delivery services."""
    @abstractmethod
    def calculate_price(self, parcel: Parcel) -> int:
        pass

    @abstractmethod
    def check_conditions(self, parcel: Parcel) -> None:
        pass

class UrbanDeliveryService(DeliveryService, ABC):
    """Interface for urban services that support fast delivery."""
    @abstractmethod
    def calculate_price(self, parcel: Parcel, fast_delivery: bool) -> int:
        pass