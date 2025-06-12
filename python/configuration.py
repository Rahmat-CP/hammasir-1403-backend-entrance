class Configuration:
    """A singleton class to hold global application configuration."""
    _instance = None

    @classmethod
    def get_instance(cls) -> 'Configuration':
        """Class method to get the single instance of the class."""
        if cls._instance is None:
            cls._instance = cls()
        return cls._instance

    def __init__(self):
        if Configuration._instance is not None:
            raise RuntimeError("This class is a singleton! Use get_instance().")
        else:
            self.base_price = 1000
            self.unit_price = 1000
            self.weight_limit = 10
            self.dimension_limit = 100