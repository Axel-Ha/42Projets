from abc import ABC, abstractmethod
from ex1.capability import HealCapability, TransformCapability
from typing import Any


class BattleError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message
        super().__init__(message)

    def __str__(self) -> str:
        return f"{self.message}"


class BattleStrategy(ABC):
    @abstractmethod
    def name(self) -> str:
        pass

    @abstractmethod
    def act(self, creature: Any) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Any) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def name(self) -> str:
        return "Normal"

    def act(self, creature: Any) -> None:
        print(creature.attack())

    def is_valid(self, creature: Any) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    def name(self) -> str:
        return "Aggressive"

    def act(self, creature: Any) -> None:
        if not self.is_valid(creature):
            raise BattleError(f"Invalid Creature "
                              f"'{creature._name}' for this aggressive strategy")
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())

    def is_valid(self, creature: Any) -> bool:
        if isinstance(creature, TransformCapability):
            return True
        else:
            return False


class DefensiveStrategy(BattleStrategy):
    def name(self) -> str:
        return "Defensive"

    def act(self, creature: Any) -> None:
        if not self.is_valid(creature):
            raise BattleError(f"Battle error, aborting tournament: Invalid Creature "
                              f"'{creature._name}' for this defensive strategy")
        print(creature.attack())
        print(creature.heal())

    def is_valid(self, creature: Any) -> bool:
        if isinstance(creature, HealCapability):
            return True
        else:
            return False
