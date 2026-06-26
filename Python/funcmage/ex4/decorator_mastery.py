from functools import wraps
from collections.abc import Callable
import time

def fireball(spell: str) -> str:
    return spell

def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time() - start_time
        print(f"Spell completed in {round(end_time,3)}seconds")
        return result
    return wrapper


def main() -> None:
    timer = spell_timer(fireball)
    print(timer("Fireball"))

if __name__ == "__main__":
    main()
