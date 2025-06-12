from dataclasses import dataclass

@dataclass(frozen=True)
class Point:
    """Represents a geographical point with x and y coordinates.
    Using a dataclass for simplicity, immutability, and automatic methods.
    """
    x: int
    y: int