import json
import logging
import copy
import re
from typing import Any, Dict

DEFAULT_MAZE_CONFIG: Dict[str, Any] = {
    "highscore_filename": "score.json",
    "number_level": 10,
    "level_size": [
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
        {"width": 10, "height": 10},
    ],
    "lives": 3,
    "points_per_pacgum": 20,
    "points_per_super_pacgum": 50,
    "points_per_ghost": 200,
    "seed": 42,
    "level_max_time": 360
}


def load_json_remove_comments(file: str) -> Dict[str, Any]:
    """Parse the Json file"""
    json_stripped = []
    try:
        with open(file, "r") as f:
            for line in f:
                line_stripped = line.split("#")[0].strip()
                if line_stripped:
                    json_stripped.append(line_stripped)
        content = "".join(json_stripped)

        if not content:
            return {}
        # Removes commas before brackets or braces
        content = re.sub(r",\s*([\]}])", r"\1", content)
        try:
            res: Dict[str, Any] = json.loads(content)
            return res
        except ValueError as e:
            logging.warning(f"Invalid JSON format in {file}: {e}")
            return {}
    except FileNotFoundError:
        logging.warning(f"Configuration file not found: {file}")
        return {}


def validate_level_size(level_size: Any) -> tuple[int, int, bool]:
    """For each level size, check if we have valide values"""
    default_width, default_height = 15, 15

    if not isinstance(level_size, dict):
        return default_width, default_height, True

    level_width = level_size.get("width")
    level_height = level_size.get("height")
    flag = False

    if isinstance(level_width, int) and 7 <= level_width <= 40:
        width = level_width
    else:
        width = default_width
        flag = True

    if isinstance(level_height, int) and 7 <= level_height <= 30:
        height = level_height
    else:
        height = default_height
        flag = True
    return width, height, flag


def validate_int_field(field: str, json_data: Dict[str, Any],
                       def_val: int,
                       min_val: int | None = None) -> int:
    """For every int field, check if we have valide value"""
    if field in json_data:
        val = json_data.get(field)
        if isinstance(val, int) and not isinstance(val, bool):
            if min_val is None or val >= min_val:
                return val
        logging.warning(f"Invalid value for {field}, default value used")
    else:
        logging.warning(f"Value {field} not present, default value used")
    return def_val


def load_game_config(file: str) -> dict[str, Any]:
    """Load and validate the game configuration file
    Applies default values for missing or invalid fields
    """
    config = copy.deepcopy(DEFAULT_MAZE_CONFIG)
    json_data = load_json_remove_comments(file)
    config["lives"] = validate_int_field(
        "lives", json_data, config["lives"], 1)

    config["points_per_pacgum"] = validate_int_field(
        "points_per_pacgum",
        json_data, config["points_per_pacgum"], 1)
    config["points_per_super_pacgum"] = validate_int_field(
        "points_per_super_pacgum",
        json_data, config["points_per_super_pacgum"], 1)

    config["points_per_ghost"] = validate_int_field(
        "points_per_ghost", json_data, config["points_per_ghost"], 1)

    config["seed"] = validate_int_field(
        "seed", json_data, config["seed"], None)

    config["level_max_time"] = validate_int_field(
        "level_max_time", json_data, config["level_max_time"], 360)

    config["number_level"] = validate_int_field(
        "number_level", json_data, config["number_level"], 10)

    if "highscore_filename" in json_data:
        score_filename = json_data["highscore_filename"]
        if (isinstance(score_filename, str)
                and score_filename.endswith(".json")):
            config["highscore_filename"] = score_filename
        else:
            logging.warning(f"{score_filename} "
                            f"is not a valid value"
                            f", default value used")
    else:
        logging.warning(
            "highscore filename not present, default value used")

    number_level = config["number_level"]
    json_level = json_data.get("level_size")

    if isinstance(json_level, list):
        list_level = list(json_level)
        len_level_list = len(list_level)

        if number_level < len_level_list:
            logging.warning("Too many level sizes provided")
            list_level = list_level[:number_level]
        elif number_level > len_level_list:
            logging.warning("Not enough level sizes provided")
            missing_level = number_level - len_level_list
            list_level.extend([{"width": 15, "height": 15}] * missing_level)

        validate_level = []
        for level in list_level:
            width, height, flag = validate_level_size(level)
            validate_level.append({"width": width, "height": height})
            if flag:
                logging.warning("Invalid level size, default value used")
        config["level_size"] = validate_level
    else:
        logging.warning("level_size missing or invalid, default value used")
        config["level_size"] = [
            {"width": 15, "height": 15} for _ in range(number_level)
        ]
    return config
