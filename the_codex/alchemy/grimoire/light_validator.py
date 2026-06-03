def validate_ingredients(ingredients: str):
    from .light_spellbook import light_spell_allowed_ingredients
    allowed_ingredients = light_spell_allowed_ingredients()

    for ingredient in ingredients:
        if ingredient.lower() not in allowed_ingredients:
            return "INVALID"
    return "VALID"
