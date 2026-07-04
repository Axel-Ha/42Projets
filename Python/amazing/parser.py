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
            if x_str.isdigit() and int(x_str) >= 0 and y_str.isdigit() and int(y_str) >= 0:
                return int(x_str), int(y_str)
        raise ValueError("The coordinates must be x,y and must be greater than 0")

    @field_validator('perfect', mode='before')
    def verify_perfect(cls, perfect: bool) -> bool:
        if isinstance(perfect, str):
            if perfect.lower() == 'true':
                return True
            elif perfect.lower() == 'false':
                return False
            else:
                raise ValueError("The perfect must be True or False")
        return perfect

    @model_validator(mode='after')
    def validate_coord(self):
        def in_maze(coord: tuple[int, int]) -> bool:
            x, y = coord
            return 0 <= x < self.width and 0 <= y < self.height

        if self.entry == self.exit:
            raise ValueError("Entry coordinates can't be the same as Exit")
        
        if not in_maze(self.entry):
            raise ValueError("The coordinates of entry must be in maze")

        if not in_maze(self.exit):
            raise ValueError("The coordinates of exit must be in maze")
        return self


def parse(file: str) -> dict[str, Any]:

    path = Path(file)
    if not path.is_file():
        raise FileNotFoundError(f"File {file} not found")
    if not path.suffix == ".txt":
        raise ValueError("File must be a .txt file")
    data = {}
    lines = path.read_text().splitlines()
    for line in lines:
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
