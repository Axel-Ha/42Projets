class Plant:
    class Stats:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def set_grow_count(self) -> None:
            self._grow_count += 1

        def get_grow_count(self) -> int:
            return self._grow_count

        def set_age_count(self) -> None:
            self._age_count += 1

        def get_age_count(self) -> int:
            return self._age_count

        def set_show_count(self) -> None:
            self._show_count += 1

        def get_show_count(self) -> int:
            return self._show_count

        def show_stats(self) -> None:
            print(f"Stats: {self.get_grow_count()} grow,"
                  f" {self.get_age_count()} age, {self.get_show_count()} show")

    def __init__(self, name: str, height: float, age: int
                 ) -> None:
        self.name = name
        self._height = height
        self._age = age
        self._stats: Plant.Stats = self.Stats()

    def show(self) -> None:
        self._stats.set_show_count()
        print(f"{self.name.capitalize()}: {self.get_height():.1f}cm,"
              f" {self.get_age()} days old")

    def set_height(self, height: float) -> None:
        self._stats.set_grow_count()
        self._height = height

    def get_height(self) -> float:
        return self._height

    def set_age(self, age: int) -> None:
        self._stats.set_age_count()
        self._age = age

    def get_age(self) -> int:
        return self._age

    @staticmethod
    def is_older_than_year(age: int) -> int:
        return age >= 365

    @classmethod
    def anonymous_plant(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._is_bloomed = False

    def get_color(self) -> str:
        return self._color

    def get_isbloomed(self) -> bool:
        return self._is_bloomed

    def set_isbloomed(self) -> None:
        self._is_bloomed = True

    def bloom(self) -> None:
        self.set_isbloomed()

    def show(self) -> None:
        super().show()
        print(f"Color: {self.get_color()}")
        if self.get_isbloomed() is False:
            print(f"{self.name.capitalize()} has not bloomed yet")
        else:
            print(f"{self.name.capitalize()} is blooming beautifully!")


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int,
                 color: str) -> None:
        super().__init__(name, height, age, color)
        self._seed = 0

    def set_seed(self, seed: int) -> None:
        self._seed = seed

    def get_seed(self) -> int:
        return self._seed

    def grow_and_bloom(self) -> None:
        self.set_height(30)
        self.set_age(20)
        self.set_seed(42)

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.get_seed()}")


class Tree(Plant):
    class Stats(Plant.Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def set_shade_count(self) -> None:
            self._shade_count += 1

        def get_shade_count(self) -> int:
            return self._shade_count

        def show_stats(self) -> None:
            super().show_stats()
            print(f"{self.get_shade_count()} shade")

    def __init__(self, name: str, height: float, age: int,
                 diameter: float) -> None:
        super().__init__(name, height, age)
        self._diameter = diameter
        self._stats: Tree.Stats = self.Stats()

    def set_diameter(self, diameter: float) -> None:
        self._diameter = diameter

    def get_diameter(self) -> float:
        return self._diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.get_diameter():.1f}cm")

    def produce_shade(self) -> None:
        self._stats.set_shade_count()
        print(f"Tree {self.name.capitalize()} now produces a shade of "
              f"{self.get_height():.1f}cm long"
              f" and {self.get_diameter():.1f}cm wide. ")


class Vegetable(Plant):
    def __init__(self, name: str, height: float,
                 age: int, harvest_season: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutri_value = 0

    def get_harvest_season(self) -> str:
        return self._harvest_season

    def set_nutri_value(self, nutri_value: int) -> None:
        self._nutri_value = nutri_value

    def get_nutri_value(self) -> int:
        return self._nutri_value

    def set_age(self, age: int) -> None:
        self._stats.set_age_count()
        super().set_age(age)

    def set_height(self, height: float) -> None:
        super().set_height(height)

    def grow(self, days: int) -> None:
        print(f"[make {self.name} grow and age for {days} days]")
        self._stats.set_grow_count()
        for i in range(1, days + 1):
            self._height += 2.1
            self._age += 1
            self.set_nutri_value(self.get_nutri_value() + 1)

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.get_harvest_season().capitalize()}")
        print(f"Nutritional value: {self.get_nutri_value()}")


def display_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name.capitalize()}]")
    plant._stats.show_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print("Is 30 days more than a year? ->", Plant.is_older_than_year(30))
    print("Is 400 days more than a year? ->", Plant.is_older_than_year(400))

    print("=== Flower")
    rose = Flower('rose', 15.0, 10, "red")
    rose.show()
    display_stats(rose)

    print(f"[asking the {rose.name} to grow and bloom]")
    rose.set_height(8)
    rose.bloom()
    rose.show()
    display_stats(rose)

    print("=== Tree")
    tree = Tree('oak', 200, 265, 5)
    tree.show()
    display_stats(tree)

    print(f"[asking the {tree.name} to produce shade]")
    tree.produce_shade()
    display_stats(tree)

    print("=== Seed")
    sunflower = Seed('sunflower', 80, 45, "yellow")
    sunflower.show()
    display_stats(sunflower)

    print(f"[make the {sunflower.name}grow, age and bloom]")
    sunflower.grow_and_bloom()
    sunflower.show()
    display_stats(sunflower)

    print("=== Anonymous")
    anonymous = Plant.anonymous_plant()
    anonymous.show()
    display_stats(anonymous)
