class Plant :
    def __init__(self, name: str, height: int, year: int):
        self.name = name
        self.height = height
        self.year = year

    def show(self):
        print(f"Created: {self.name}: {round(self.height, 2)}cm, {self.year} days old")
    
    def grow(self, growth: int):
        self.height += growth
        
    def age(self, year: int):
        self.year += year
        
    
        
if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    garden = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)
    ]

    for plant in garden:
        plant.show()
