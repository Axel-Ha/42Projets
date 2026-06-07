from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: list[str]
                      ) -> str:
    list_ingredient = ", ".join(ingredients)
    return (f"Spell recorded: {spell_name} "
            f"{list_ingredient} - {validate_ingredients(ingredients)}")
