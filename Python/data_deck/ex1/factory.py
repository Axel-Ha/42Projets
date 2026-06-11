from ex0 import CreatureFactory
from ex0.creature import Creature
from .creature import Sproutling, Bloomelle, Shiftling, Morphagon


class HealingCreatureFactory(CreatureFactory):
    def family_name(self) -> str:
        return "Healing"

    def create_base(self) -> Creature:
        return Sproutling("Sproutling", "Grass")

    def create_evolved(self) -> Creature:
        return Bloomelle("Bloomelle", "Grass/Fairy")


class TransformCreatureFactory(CreatureFactory):
    def family_name(self) -> str:
        return "Transform"

    def create_base(self) -> Creature:
        return Shiftling("Shiftling", "Normal")

    def create_evolved(self) -> Creature:
        return Morphagon("Morphagon", "Normal/Dragon")
