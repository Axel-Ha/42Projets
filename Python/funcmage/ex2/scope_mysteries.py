from collections.abc import Callable
from typing import Any


def mage_counter() -> Callable[[], int]:
    count = 0

    def count_function() -> int:
        nonlocal count
        count += 1
        return count
    return count_function


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    stack = initial_power

    def accumulator(add: int) -> int:
        nonlocal stack
        stack += add
        return stack
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    def enchantment(item_name: str) -> str:
        return enchantment_type + " " + item_name
    return enchantment


def memory_vault() -> dict[str, Callable]:
    storage: dict[str, Any | None] = {}

    def store(key: str, value: Any) -> None:
        storage[key] = value

    def recall(key: str) -> Any:
        if key not in storage:
            return "Memory not found"
        else:
            return storage[key]
    return {'store': store, 'recall': recall}


def main() -> None:
    counter_a = mage_counter()
    counter_b = mage_counter()
    print("Testing mage counter...")
    print(f"counter_a call 1: {counter_a()}")
    print(f"counter_a call 2: {counter_a()}")
    print(f"counter_b call 1: {counter_b()}")

    print()
    print("Testing spell accumulator...")
    accumulator = spell_accumulator(100)
    print(f"base 100, add 20: {accumulator(20)}")
    print(f"base 100, add 30: {accumulator(30)}")

    print()
    print("Testing enchantment factory...")
    enchanment_1 = enchantment_factory("Frozen")
    print(enchanment_1("sword"))

    print()
    print("Testing memory vault...")
    vault = memory_vault()
    print("Store 'secret' = 42")
    vault['store']('secret', 42)

    print(f"Recall 'secret': {vault['recall']('secret')}")
    print(f"Recall 'unknown': {vault['recall']('unknown')}")


if __name__ == "__main__":
    main()
