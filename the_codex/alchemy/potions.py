from .elements import create_earth, create_air
from elements import create_fire, create_water

def healing_potion():
    return ("Healing potion brewind with "
    f"'{create_earth()}' and '{create_air()}'")


def strength_potion():
    return ("Strength potion brewind with "
    f"'{create_fire()}' and '{create_water()}'")
