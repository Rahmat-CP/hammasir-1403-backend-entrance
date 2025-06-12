from point import Point
from parcel import Parcel
from bike_delivery import BikeDelivery

if __name__ == "__main__":
    
    print("--- [Test Case 1: Valid Parcel] ---")
    valid_parcel = (Parcel.builder()
                    .weight(8)
                    .length(20)
                    .width(30)
                    .flammable(False)
                    .source(Point(1, 1))
                    .destination(Point(4, 5))
                    .insurance_price(10000)
                    .build())
    
    bike_service = BikeDelivery()
    bike_service.check_conditions(valid_parcel)
    normal_price = bike_service.calculate_price(valid_parcel)
    fast_price = bike_service.calculate_price(valid_parcel, fast_delivery=True)
    print(f"Standard Delivery Price: {normal_price}")
    print(f"Fast Delivery Price: {fast_price}\n")
    
    print("--- [Test Case 2: Heavy Parcel] ---")
    heavy_parcel = (Parcel.builder()
                    .weight(15)
                    .build())
    bike_service.check_conditions(heavy_parcel)
    
    print("\n--- [Test Case 3: Flammable Parcel] ---")
    flammable_parcel = (Parcel.builder()
                       .weight(5)
                       .flammable(True)
                       .build())
    bike_service.check_conditions(flammable_parcel)