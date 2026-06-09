from ex0.creature import Creature
from . import HealCapability, TransformCapability


class Sproutling(Creature, HealCapability):
    def attack(self) -> str:
        return f"{self._name} uses Vine Whip"

    def heal(self, target: Creature | None = None) -> str:
        if target:
            return f"{target._name} is healed by {self._name}"
        else:
            return f"{self._name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    def attack(self) -> str:
        return f"{self._name} uses Vine Whip"

    def heal(self, target: Creature | None = None) -> str:
        if target:
            return f"{target._name} is healed by {self._name}"
        else:
            return f"{self._name} heals itself for and the others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str, type: str) -> None:
        super().__init__(name, type)
        self._is_transformed = False

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self._name} shifts into a sharper form!"

    def revert(self) -> str:
        self._is_transformed = False
        return f"{self._name} returns to normal"

    def attack(self) -> str:
        if self._is_transformed is True:
            return f"{self._name} performs a boosted strike1"
        else:
            return f"{self._name} attacks normally."


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str, type: str) -> None:
        super().__init__(name, type)
        self._is_transformed = False

    def transform(self) -> str:
        self._is_transformed = True
        return f"{self._name} morphs into a dragonic battle form!"
    
    def revert(self) -> str:
        self._is_transformed = False
        return f"{self._name} returns to normal"

    def attack(self) -> str:
        if self._is_transformed is True:
            return f"{self._name} unleashed a devastating morph strike!"
        else:
            return f"{self._name} attacks normally."
