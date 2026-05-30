class Plant :
    def __init__(self, name: str, height: int, year: int):
        if height < 0 or year < 0 :
            self.name = name
            self._height = 0
            self._age = 0
        else:
            self.name = name
            self._height = height
            self._age = year

    def show(self, text: str):
        print(f"{text}: {self.name}: {round(self.get_height(), 2)}cm, {self.get_age()} days old")
    
    def set_height(self, height: int):
        if(height < 0):
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")

        else :
            self._height = height
            print(f"Height updated: {height}cm")

    def get_height(self):
        return self._height

        
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
    rose = Plant('Rose', 15.0, 10)
    rose.show("Plant created")
    
    rose.set_height(25)
    rose.set_age(30)

    rose.set_height(-10)
    rose.set_age(-30)
    rose.show("Current state")
