class GardenError(Exception):
    def __init__(self, message:
                 str = "Unknown garden error") -> None:
        self.message = message
        super().__init__(message)

    def __str__(self) -> str:
        return f"{self.message}"


class PlantError(GardenError):
    def __init__(self, message:
                 str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message:
                 str = "Unknown water error") -> None:
        super().__init__(message)


def test_custom_error() -> None:
    print("=== Custom Garden Errors Demo ===")
    print()

    print("Testion PlantError...")
    try:
        raise PlantError("The tomato plant is wilting")
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print()
    print("Testion WaterError...")
    try:
        raise WaterError("Not enough water in the tank")
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print()
    print("Testing catching all garden errors...")
    try:
        raise PlantError("The tomato plant is wilting")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        raise WaterError("Not enough water in the tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    print()
    print("All custom error types work correctly")


test_custom_error()
