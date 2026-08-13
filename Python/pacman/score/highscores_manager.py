import json
from pathlib import Path


def get_highscores(filename: str) -> dict[str, int]:
    """Get the file with the best scores"""
    my_file = Path(filename)
    if my_file.is_file():
        with open(my_file, "r", encoding="utf-8") as file:
            try:
                result: dict[str, int] = json.load(file)
                return result
            except json.decoder.JSONDecodeError:
                return {}
    else:
        return {}


def set_highscore(filename: str, new_highscore: tuple[str, int]) -> None:
    """Set the a new highscore in the file"""
    scores = list(get_highscores(filename=filename).items())
    scores.append(new_highscore)
    scores.sort(key=lambda s: s[1], reverse=True)
    scores_copy = []
    name_already_see = []

    # Keep the best score from the same player
    for name, score in scores:
        if name not in name_already_see:
            name_already_see.append(name)
            scores_copy.append((name, score))
        else:
            pass

    # Keep the 10 best scores
    scores_copy = scores_copy[:10]

    # Create an dict
    new_highscore_list = {}
    for name, score in scores_copy:
        new_highscore_list[name] = score

    with open(filename, "w", encoding="utf-8") as file:
        file.write(json.dumps(new_highscore_list, indent=4))
