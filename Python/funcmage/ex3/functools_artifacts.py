from functools import reduce, partial, lru_cache, singledispatch
from collections.abc import Callable
import operator
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    match operation:
        case "add":
            return reduce(operator.add, spells)
        case "multiply":
            return reduce(operator.mul, spells)
        case "max":
            return reduce(max, spells)
        case "min":
            return reduce(min, spells)
        case _:
            raise ValueError("Wrong operator")


def enchantment(power: int, element: str, target: str) -> str:
    return f"power: {power}, element: {element}, target: {target}"


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {'Ice': partial(base_enchantment, 50, "Ice"),
            'Wind': partial(base_enchantment, 50, "Wind"),
            'Fire': partial(base_enchantment, 50, "Fire")}


@lru_cache()
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n-1) + memoized_fibonacci(n-2)


def spell_dispatcher() -> Callable[[Any], str]:
    return dispatcher


@singledispatch
def dispatcher(spell: Any) -> str:
    return "Unknown spell type"


@dispatcher.register(int)
def _1(damage: int) -> str:
    return f"{damage} damage"


@dispatcher.register(str)
def _2(enchantment: str) -> str:
    return f"{enchantment}"


@dispatcher.register(list)
def _3(multi_cast: list) -> str:
    return f"{len(multi_cast)} spells"


def main() -> None:
    spell_powers = [44, 11, 20, 15, 32, 37]
    operations = ['add', 'multiply', 'max', 'min']
    print("Testing spell reducer...")
    print(spell_reducer(spell_powers, operations[2]))
    print()

    print("Testing partial enchanter...")
    partial_test = partial_enchanter(enchantment)
    print(partial_test['Fire']("Wizard"), partial_test['Ice']("Wizard"))
    print()

    print("Testing memoized fibonacci...")
    fibo = memoized_fibonacci(10)
    print(fibo)
    print(memoized_fibonacci.cache_info())
    print()

    print("Testing spell dispatcher...")
    dispatch = spell_dispatcher()
    print(f"{dispatch(42)}")
    print(f"{dispatch('Fireball')}")
    print(f"{dispatch(["Fire","Ice","Earth"])}")
    print(f"{dispatch({"Fire": "yeah"})}")


if __name__ == "__main__":
    main()
