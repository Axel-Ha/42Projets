class Plant :
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = height
        self._age = age

    def show(self):
        print(f"{self.name.capitalize()}: {self.get_height():.1f}cm, {self.get_age()} days old")
    
    def set_height(self, height: float):
        self._height = height

    def get_height(self):
        return self._height
        
    def set_age(self, age: int):
        self._age = age

    def get_age(self):
        return self._age
    
class Flower(Plant) :
    def __init__(self, name: str, height: float, age: int, color: str) :
        super().__init__(name, height, age)
        self._color = color
        self._is_bloomed = False
    
    def get_color(self):
        return self._color
    
    def get_isbloomed(self):
        return self._is_bloomed
    
    def set_isbloomed(self): 
        self._is_bloomed = True

    def bloom(self):
        print(f"[asking the {self.name} to bloom]")
        self.set_isbloomed()
    
    def show(self):
        super().show()
        print(f"Color: {self.get_color()}")
        if(self.get_isbloomed() == False) :
            print(f"{self.name.capitalize()} has not bloomed yet")
        else :
            print(f"{self.name.capitalize()} is blooming beautifully!")

class Tree(Plant) :
    def __init__(self, name: str, height: float, age: int, diameter: int):
        super().__init__(name,height,age)
        self._diameter = diameter
    
    def set_diameter(self, diameter: float ):
        self._diameter = diameter
    
    def get_diameter(self):
        return self._diameter
    
    def show(self): 
        super().show()
        print(f"Trunk diameter: {self.get_diameter():.1f}cm")
    
    def produce_shade(self):
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name.capitalize()} now produces a shade of {self.get_height():.1f}cm long and {self.get_diameter():.1f}cm wide. ")

class Vegetable(Plant) :
    def __init__(self, name: str, height: float, age: int, harvest_season: str):
        super().__init__(name,height,age)
        self._harvest_season = harvest_season
        self._nutri_value = 0

    def get_harvest_season(self):
        return self._harvest_season
        
    def set_nutri_value(self, nutri_value: int):
        self._nutri_value = nutri_value

    def get_nutri_value(self):
        return self._nutri_value
    
    def set_age(self, age : int):
        return super().set_age(age)
    
    def set_height(self, height : float):
        return super().set_height(height)
    
    def grow(self, days):
        print(f"[make {self.name} grow and age for {days} days]")
        for i in range(1,days + 1) :
            self.set_height(self.get_height() + 2.1)
            self.set_age(self.get_age() + 1)
            self.set_nutri_value(self.get_nutri_value() + 1)

    def show(self): 
        super().show()
        print(f"Harvest season: {self.get_harvest_season().capitalize()}")
        print(f"Nutritional value: {self.get_nutri_value()}")
    
if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower('rose', 15, 10, "red")
    rose.show()
    rose.bloom()
    rose.show()

    print("=== Tree")
    oak = Tree("oak",200,365,5)
    oak.show()
    oak.produce_shade()
    
    print("=== Vegetable")
    tomato = Vegetable("tomato",5,10,"april")
    tomato.show()
    tomato.grow(20)
    tomato.show()
