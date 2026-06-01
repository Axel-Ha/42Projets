class Plant :
    def __init__(self, name: str, growth: int, age: int):
        self.name = name
        self._growth = growth
        self._age = age

    def show(self, text: str):
        print(f"{text}: {self.name}: {self.get_growth():.2f}cm, {self.get_age()} days old")
    
    def set_growth(self, growth: int):
        if(growth < 0):
            print(f"{self.name}: Error, growth can't be negative")
            print("growth update rejected")

        else :
            self._growth = growth
            print(f"growth updated: {growth}cm")

    def get_growth(self):
        return self._growth

        
    def set_age(self, age: int):
        if(age < 0):
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")

        else :
            self._age = age
            print(f"Age updated: {age}")

    def get_age(self):
        return self._age
        
    
        
if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant('Rose', 15, 10)
    rose.show("Plant created")
    
    rose.set_growth(25)
    rose.set_age(30)

    rose.set_growth(-10)
    rose.set_age(-30)
    rose.show("Current state")
