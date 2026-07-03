from typing import Any
from pathlib import Path
from pydantic import BaseModel, Field, model_validator, ValidationError, field_validator


class ConfigModel(BaseModel):
    width: int = Field(..., gt=2, alias="WIDTH")
    height: int = Field(..., gt=2, alias="HEIGHT")
    entry: tuple[int, int] = Field(..., alias="ENTRY")
    exit: tuple[int, int] = Field(..., alias="EXIT")
    output_file: str = Field(..., alias="OUTPUT_FILE")
    perfect: bool = Field(..., alias="PERFECT")
    seed: int | None = Field(default=42, ge=0, alias="SEED")

    @field_validator('entry', 'exit', mode="before")
    def verify_coord(cls, coord: tuple[int, int]) -> tuple[int, int]:
        if isinstance(coord, tuple):
            return coord
        if isinstance(coord, str):
            values = coord.split(",")
            if len(values) != 2:
                raise ValueError("The coordinates must be x,y")
            else:
                x_str, y_str = [val.strip() for val in values]
            if x_str.isdigit() or y_str.isdigit():
                return int(x_str),int(y_str),
        raise ValueError("The coordinates must be x,y")


def parse(file: str) -> dict[str, Any]:
    path = Path.open(file).readlines()
    data = {}
    for line in path:
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        key, sep, value = line.partition('=')
        if not sep:
            raise ValueError("Expected format KEY=VALUE")
        data[key.strip()] = value.strip()
    return data


def set_config(file: str) -> ConfigModel:
    config = parse(file)
    return ConfigModel(**config)


parser = set_config("test.txt")
