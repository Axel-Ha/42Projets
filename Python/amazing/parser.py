from typing import Any
from pathlib import Path

def parse(file : str) -> dict[str,Any]:
    path = Path.open(file).readlines()
    config = {}
    for line in path:
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        key,sep,value = line.partition('=')
        if not sep:
            raise ValueError("Expected format KEY=VALUE")
        config[key] = value
    
    print(config)

parse("test.txt")