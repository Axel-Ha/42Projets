import math


def get_player_pos() -> tuple[float, ...]:
    while True:
        nbrs = input("Enter new coordinates as floats in format, 'x,y,z': ")
        parts = nbrs.split(",")
        if len(parts) != 3:
            print("Invalide syntax")
            continue
        try:
            coords = []
            for nbr in parts:
                coords.append(float(nbr))
            return tuple(coords)
        except ValueError as e:
            print(f"Error on parameter {nbr}: {e}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    x1, y1, z1 = get_player_pos()
    print(f"Got a first tuple: {x1, y1, z1}")
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    distance = math.sqrt((x1)**2 + (y1)**2 + (z1)**2)
    print(f"Distance to center: {distance:.4f}")

    print()
    x2, y2, z2 = get_player_pos()
    distance = math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)
    print(f"Distance tbetween the 2 sets of coordinates: {distance:.4f}")
