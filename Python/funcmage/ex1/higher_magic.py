from collections.abc import Callable


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def attack(target: str, power: int) -> str:
    return f"The attack deal {power} damage to {target}"


def spell_power(spell: str, power: int) -> str:
    return f"{spell} {power}"


def condition_spell(target: str | None, power: int) -> bool:
    return False if power < 30 else True


def spell_combiner(spell1: Callable[[str, int], str],
                   spell2: Callable[[str, int], str]
                   ) -> Callable[[str, int], str]:
    def cast(target: str, power: int) -> str:
        result: str = spell1(target, power)
        result += ", " + spell2(target, power)
        return result
    return cast


def power_amplifier(base_spell: Callable[[str, int], str],
                    multiplier: int
                    ) -> Callable[[str, int], str]:
    def amplifier(spell: str, power: int) -> str:
        power_amplified = power * multiplier
        return base_spell(spell, power_amplified)
    return amplifier


def conditional_caster(condition: Callable[[str | None, int], bool], spell:
                       Callable[[str, int], str]
                       ) -> Callable[[str, int], str]:
    def cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        else:
            return "Spell fizzled"
    return cast


def spell_sequence(spells: list[Callable[[str, int], str]]
                   ) -> Callable[[str, int], list[str]]:
    def cast(target: str, power: int) -> list[str]:
        list_spell = []
        for spell in spells:
            list_spell.append(spell(target, power))
        return list_spell
    return cast


def main() -> None:
    print("Testing spell combiner...")
    combined = spell_combiner(heal, attack)
    print(f"Combined spell result: {combined('Dragon', 12)}")

    print()
    print("Testing spell amplified...")
    spell_amplified = power_amplifier(spell_power, 3)
    print("before: Ice canon 3")
    print(f"after: {spell_amplified('Ice canon', 3)}")

    print()
    print("Testing conditional cast...")
    conditional_spell = conditional_caster(condition_spell, attack)
    print(conditional_spell('Dragon', 30))
    print(conditional_spell('Dragon', 29))

    print()
    print("Testing spell sequence...")
    spells = spell_sequence([attack, heal, heal, attack])
    print(spells('Dragon', 30))


if __name__ == "__main__":
    main()
