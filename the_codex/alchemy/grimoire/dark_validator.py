from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: list[str]) -> str:
    allowed_ingredients = dark_spell_allowed_ingredients()

    for ingredient in ingredients:
        if ingredient.lower() not in allowed_ingredients:
            return "INVALID"
    return "VALID"
