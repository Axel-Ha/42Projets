from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from space_stations import SPACE_STATIONS
import random


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: str | None = Field(default=None, max_length=200)


def main():
    rand_int = random.randint(0, len(SPACE_STATIONS) - 1)
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")
    space_station = SpaceStation(**SPACE_STATIONS[rand_int])
    print(f"ID: {space_station.station_id}")
    print(f"Name: {space_station.name}")
    print(f"Crew: {space_station.crew_size} people")
    print(f"Power: {space_station.power_level}%")
    print(f"Oxygen: {space_station.oxygen_level}%")
    if space_station.is_operational:
        print("Status: Operational")
    else:
        print("Status: Non Operational")
    print()
    print("========================================")
    print("Expected validation error:")
    ERROR_SPACE_STATIONS = {
        'station_id': 'LGW125',
        'name': 'Titan Mining Outpost',
        'crew_size': 22,
        'power_level': 76.4,
        'oxygen_level': 95.5,
        'last_maintenance': '2023-07-11T00:00:00',
        'is_operational': True,
        'notes': None
    }

    try:
        space_station = SpaceStation(**ERROR_SPACE_STATIONS)
    except ValidationError as e:
        print(f"{e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
