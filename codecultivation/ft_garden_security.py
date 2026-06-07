class Plant:
    def __init__(self, name: str, height: float, age: int
                 ) -> None:
        self.name = name
        self._height = height
        self._age = age

    def show(self, text: str) -> None:
        print(f"{text}: {self.name}: {round(self.get_height())}cm, "
              f"{self.get_age()} days old")

    def set_height(self, height: int) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("height update rejected")

        else:
            self._height = height
            print(f"height updated: {height}cm")

    def get_height(self) -> float:
        return self._height

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")

        else:
            self._age = age
            print(f"Age updated: {age}")

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant('Rose', 15, 10)
    rose.show("Plant created")

    rose.set_height(25)
    rose.set_age(30)

    rose.set_height(-10)
    rose.set_age(-30)
    rose.show("Current state")
