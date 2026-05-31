class Plant :
    def __init__(self, name: str, height: int, days: int):
        self.name = name
        self.height = height
        self.days = days

    def show(self):
        print(f"Created: {self.name}: {self.height:.2f}cm, {self.days} days old")
    
    def grow(self, growth: int):
        self.height += growth
        
    def age(self, days: int):
        self.days += days
        
    
        
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
