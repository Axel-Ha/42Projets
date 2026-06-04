import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    length = len(sys.argv) - 1
    inventory = {}

    for arg in sys.argv[1:]:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue
        item, qty = arg.split(":")
        try:
            qty = int(qty)
        except ValueError as e:
            print(f"Quantity error for '{item}': {e}")
            continue
        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue
        inventory[item] = qty

    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")

    count = sum(inventory.values())
    print(f"Total quantity of the {len(inventory.values())} "
          f"items: {count}")

    for item, nbr in inventory.items():
        print(f"Item {item} represents "
              f"{round((nbr / count)*100, 1)}%")

    max_abundant, qty_max = max(inventory.items(), key=lambda x: x[1])
    least_abundant, qty_least = min(inventory.items(), key=lambda x: x[1])
    print(f"Item most abundant: {max_abundant} with quantity {qty_max}")
    print(f"Item least abundant: {least_abundant} with quantity {qty_least}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")