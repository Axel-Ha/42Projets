class Plant :
    def __init__(self, name: str, height: float, days: int):
        self.name = name
        self.height = height
        self.days = days

    def show(self):
        print(f"{self.name}: {self.height:.2f}cm, {self.days} days old")
    
    def grow(self, growth: float):
        self.height += growth
        
    def age(self, days: int):
        self.days += days
        
    
        
if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    
    rose = Plant("Rose", 25, 30)
    rose.show()
    growth = 0.0
    for i in range(1,8):
        rose.grow(0.8)
        rose.age(1)
        growth += 0.8
        print(f"=== Day {i} ===")
        rose.show()
    print(f"Growth this week: {growth}")
