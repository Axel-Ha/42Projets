from typing import Generator
import random


def gen_event() -> Generator[tuple[str, str], None, None]:
    name = ["alice", "bob", "dylan", "charlie"]
    action = ["grab", "sleeb", "eat", "run",
              "climb", "move", "swim"]
    while True:
        player = random.choice(name)
        act = random.choice(action)
        yield (player, act)


def consume_event(
    list_events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:

    while len(list_events) > 0:
        rand_int = random.randint(0, len(list_events)-1)
        pick_event = list_events.pop(rand_int)
        yield pick_event


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    gen = gen_event()
    all_events = []
    for i in range(1000):
        player, action = next(gen)
        print(f"Event {i}: Player {player} did action {action}")

    for i in range(10):
        all_events.append(next(gen))

    print(f"Build list of 10 events: {all_events}")
    for events in consume_event(all_events):
        print(f"Got event from list: {events}")
        print(f"Remains in list: {all_events}")
