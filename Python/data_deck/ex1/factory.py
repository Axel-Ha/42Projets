from ex0 import CreatureFactory
from ex0.creature import Creature
from .creature import HealingCreature, TransformingCreature, Sproutling, Bloomelle, Shiftling, Morphagon
from .capability import HealCapability, TransformCapability

class HealingCreatureFactory(CreatureFactory):
    def family_name(self) -> str:
        return "Healing"

    def create_base(self) -> HealingCreature:
        return Sproutling("Sproutling", "Grass")

    def create_evolved(self) -> HealingCreature:
        return Bloomelle("Bloomelle", "Grass/Fairy")


class TransformCreatureFactory(CreatureFactory):
    def family_name(self) -> str:
        return "Transform"

    def create_base(self) -> TransformingCreature:
        return Shiftling("Shiftling", "Normal")

    def create_evolved(self) -> TransformingCreature:
        return Morphagon("Morphagon", "Normal/Dragon")
