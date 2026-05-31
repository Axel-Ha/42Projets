def ft_seed_inventory(seed_type: str, quantity: int, unit: str):
    valid_seeds = ["tomato", "carrot", "lettuce"]
    if seed_type in valid_seeds:
        print(seed_type.capitalize(), "seeds:", quantity, unit, "available")
    else :
        print("Unknown seed type")