from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleError, BattleStrategy, NormalStrategy, AggressiveStrategy, DefensiveStrategy


def ft_battle(oppenents: list[tuple[CreatureFactory, BattleStrategy]]):
    list_oppenents = []
    for factory, strategy in oppenents:
        oppenents_formats = f"({factory.family_name()}+{strategy.name()})"
        list_oppenents.append(oppenents_formats)
    list_oppenents = ", ".join(list_oppenents)
    print(f"[{list_oppenents}]")
    print("*** Tournament ***")
    print(f"{len(oppenents)} oppenents involved")
    print()

    list_oppenents = []
    for factory, strategy in oppenents:
        creature = factory.create_base()
        list_oppenents.append([creature, strategy])
    i = 0
    while i < len(list_oppenents):
        j = i + 1
        while j < len(list_oppenents):
            print("* Battle *")
            creature1, strategy1 = list_oppenents[i]
            creature2, strategy2 = list_oppenents[j]
            print(creature1.describe())
            print("vs")
            print(creature2.describe())
            print("now fight!")
            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
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
    agressive_factory = AggressiveStrategy()
    aqua_factory = AquaFactory()
    transform_factory = TransformCreatureFactory()
    ft_battle([[flame_factory, normal_strategy], [
              healing_factory, defensive_strategy]])
    print()
    print("Tournament 1 (error)")
    ft_battle([[flame_factory, agressive_strategy], [
              healing_factory, defensive_strategy]])
    
    print()
    print("Tournament 2 (multiple)")
    ft_battle([[aqua_factory, normal_strategy], [
              healing_factory, defensive_strategy],
              [transform_factory, agressive_strategy]])