import random


def gen_player_achievement() -> set[str]:
    achievements = set(["Crafting Genius", "Strategist",
                       "World Savior", "Speed Runner",
                        "Survivor", "Master Explorer",
                        "Treasure Hunter", "Unstoppable", "First Steps",
                        "Collector Supreme", "Untouchable", "Sharp Mind",
                        "Boss Slayer"])

    list_achievements = list(achievements)
    rand_nbr = random.randint(3, len(list_achievements))
    achievements_picked = random.sample(list_achievements, rand_nbr)
    return set(achievements_picked)


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    achievements = set(["Crafting Genius", "Strategist",
                       "World Savior", "Speed Runner",
                        "Survivor", "Master Explorer",
                        "Treasure Hunter", "Unstoppable", "First Steps",
                        "Collector Supreme", "Untouchable", "Sharp Mind",
                        "Boss Slayer"])
    alice = gen_player_achievement()
    bob = gen_player_achievement()
    charlie = gen_player_achievement()
    dylan = gen_player_achievement()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")

    print()
    print(f"All distinct achievements: {alice | bob | charlie | dylan}")

    print()
    print(f"Common achievements: {alice & bob & charlie & dylan}")

    print()
    print(f"Only Alice has: {alice - (bob | charlie | dylan)}")
    print(f"Only Bob has: {bob - (alice | charlie | dylan)}")
    print(f"Only Charlie has: {charlie - (bob | alice | dylan)}")
    print(f"Only Dylan has: {dylan - (bob | charlie | alice)}")

    print()
    print(f"Alice is missing: {achievements - alice}")
    print(f"Bob is missing: {achievements - bob}")
    print(f"Charlie is missing: {achievements - charlie}")
    print(f"Dylan is missing: {achievements - dylan}")
