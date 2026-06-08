from ex0 import Creature, CreatureFactory, FlameFactory, AquaFactory


def check_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolve = factory.create_evolved()
    print(evolve.describe())
    print(evolve.attack())


def battle(flame_factory: CreatureFactory,
           aqua_factory: CreatureFactory) -> None:
    print("Testing battle")
    aqua = aqua_factory.create_base()
    print(aqua.describe())
    print("vs.")
    flame = flame_factory.create_base()
    print(aqua.describe())
    print("fight")
    print(flame.attack())
    print(aqua.attack())


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    check_factory(flame_factory)
    print()
    check_factory(aqua_factory)
    print()

    battle(flame_factory, aqua_factory)
