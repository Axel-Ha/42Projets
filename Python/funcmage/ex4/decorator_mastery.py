from functools import wraps
from collections.abc import Callable
import time
import random


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < 3:
            return False
        for char in name:
            if not (char.isalpha() or char == ' '):
                return False
        return True
    
    def cast_spell(self, spell_name: str, power: int) -> str:
        @power_validator(10)
        def func(power: int, spell_name: str):
            return f"Successfully cast {spell_name} with {power} power"
        return func(power, spell_name)

def fireball(spell: str) -> str:
    return spell


def ice(power: int, spell: str):
    return f"{spell} did {power} damage"


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start_time = time.time()
        result = func(*args, **kwargs)
        time.sleep(0.1)
        end_time = time.time() - start_time
        print(f"Spell completed in {round(end_time, 3)}seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator_factory(func: Callable):
        @wraps(func)
        def wrapper(*args, **kwargs):
            if args[0] < min_power:
                return "Insufficient power for this spell"
            else:
                return func(*args, **kwargs)
        return wrapper
    return decorator_factory


def retry_spell(max_attempts: int) -> Callable:
    def retry_decorator(func: Callable):
        @wraps(func)
        def wrapper(*args, **kwargs):
            for i in range(1, max_attempts):
                rand = random.randint(1, 2)
                if rand == 2:
                    print(
                        f"Spell failed, retrying... (attempt {i}/{max_attempts})")
                else:
                    return func(*args, **kwargs)
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return retry_decorator


def main() -> None:
    print("Testing spell timer...")
    timer = spell_timer(fireball)
    print(timer("Fireball"))
    print()

    print("Testing power validator...")
    validator = power_validator(30)
    ice_validator = validator(ice)
    print(ice_validator(50, "ice knife"))
    print(ice_validator(20, "ice knife"))
    print()

    print("Testing retrying spell...")
    retry = retry_spell(3)(ice)
    print(retry(50, "ice knife"))
    print()

    print("Testing MageGuild...")
    print(MageGuild.validate_mage_name('ne'))
    print(MageGuild.validate_mage_name('Merlin The Great'))
    mage = MageGuild()
    print(mage.cast_spell('Ice', 50))
    print(mage.cast_spell('Flame', 0))


if __name__ == "__main__":
    main()
