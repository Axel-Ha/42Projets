class Plant:
    def __init__(self, name: str, growth: int, age: int):
        self.name = name
        self.growth = growth
        self.age = age

    def show(self):
        print(f"{self.name}: {self.growth}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")

    rose = Plant("Rose", 25, 30)
    sunflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)

    rose.show()
    sunflower.show()
    cactus.show()
