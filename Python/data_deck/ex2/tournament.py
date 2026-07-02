from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleError, BattleStrategy, NormalStrategy
from ex2 import AggressiveStrategy, DefensiveStrategy
from ex0.creature import Creature


def ft_battle(oppenents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    list_oppenents = []
    for factory, strategy in oppenents:
        oppenents_formats = f"({factory.family_name()}+{strategy.name()})"
        list_oppenents.append(oppenents_formats)
    oppenents_str = ", ".join(list_oppenents)
    print(f"[{oppenents_str}]")
    print("*** Tournament ***")
    print(f"{len(oppenents)} oppenents involved")
    print()

    list_fighters: list[tuple[Creature, BattleStrategy]] = []
    for factory, strategy in oppenents:
        creature = factory.create_base()
        list_fighters.append((creature, strategy))
    i = 0
    while i < len(list_fighters):
        j = i + 1
        while j < len(list_fighters):
            print("* Battle *")
            opponent1, strategy1 = list_fighters[i]
            opponent2, strategy2 = list_fighters[j]
            print(opponent1.describe())
            print("vs")
            print(opponent2.describe())
            print("now fight!")
            try:
                strategy1.act(opponent1)
                strategy2.act(opponent2)
                print()
            except BattleError as e:
                print(f"Battle error, aborting tournament: {e}")
            j += 1
        i += 1


if __name__ == "__main__":
    print("Tournament 0 (basic)")
    normal_strategy = NormalStrategy()
    defensive_strategy = DefensiveStrategy()
    agressive_strategy = AggressiveStrategy()
    healing_factory = HealingCreatureFactory()
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    transform_factory = TransformCreatureFactory()
    ft_battle([(flame_factory, normal_strategy), (
              healing_factory, defensive_strategy)])
    print()
    print("Tournament 1 (error)")
    ft_battle([(flame_factory, agressive_strategy), (
              healing_factory, defensive_strategy)])

    print()
    print("Tournament 2 (multiple)")
    ft_battle([(aqua_factory, normal_strategy), (
              healing_factory, defensive_strategy),
        (transform_factory, agressive_strategy)])
