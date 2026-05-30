class Plant :
    def __init__(self, name: str, height: int, year: int):
        self.name = name
        self.height = height
        self.year = year

    def show(self):
        print(f"{self.name}: {round(self.height, 2)}cm, {self.year} days old")
    
    def grow(self, growth: int):
        self.height += growth
        
    def age(self, year: int):
        self.year += year
        
    
        
if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    
    rose = Plant("Rose", 25, 30)
    rose.show()
    growth = 0    
    for i in range(1,8):
        rose.grow(0.8)
        rose.age(1)
        growth += 0.8
        print(f"=== Day {i} ===")
        rose.show()
    print(f"Growth this week: {growth}")
