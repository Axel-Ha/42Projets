from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients():
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str):
    list_ingredient = ", ".join(ingredients)
    return (f"Spell recorded: {spell_name} "
            f"{list_ingredient} - {validate_ingredients(ingredients)}")
