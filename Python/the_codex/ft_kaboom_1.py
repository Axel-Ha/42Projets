
print("=== Kaboom 1 ===")
print("Access to alchemy/grimoire/dark_spellbook.py directly")
print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")
try:
    from alchemy.grimoire.dark_spellbook import dark_spell_record
    print(f"Testing record light spell: "
          f"{dark_spell_record(
              "Dark magic", ["frogs", "eyeball", "arsenic"])}")
except ImportError as e:
    print(f"Import Error : {e}")
