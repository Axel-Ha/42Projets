class Plant:
    def __init__(self, name: str, growth: float, days: int
                 ) -> None:
        self.name = name
        self.growth = growth
        self.days = days

    def show(self) -> None:
        print(f"Created: {self.name}: {self.growth:.2f}cm, "
              f"{self.days} days old")

    def grow(self, growth: float) -> None:
        self.growth += growth

    def age(self, days: int) -> None:
        self.days += days


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    garden = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
    ]

    for plant in garden:
        plant.show()
