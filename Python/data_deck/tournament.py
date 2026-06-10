from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleStrategy, NormalStrategy, AggressiveStrategy, DefensiveStrategy


def ft_battle(creature: list(tuple[CreatureFactory, BattleStrategy])):
    pass

if __name__ == "__main__":
    print("Tournament 0 (basic)")
    flame_factory = FlameFactory()
    flameling = flame_factory.create_base()
    
