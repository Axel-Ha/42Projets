def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: list[str]
                       ) -> str:
    from .light_validator import validate_ingredients
    list_ingredient = ", ".join(ingredients)
    return (f"Spell recorded: {spell_name} "
            f"{list_ingredient} - {validate_ingredients(ingredients)}")
