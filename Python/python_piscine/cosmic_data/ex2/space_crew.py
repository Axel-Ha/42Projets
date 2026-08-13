from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum
from typing_extensions import Self
from space_missions import SPACE_MISSIONS
import random


class Rank(Enum):
    cadet = 'cadet'
    officer = 'officer'
    lieutenant = 'lieutenant'
    captain = 'captain'
    commander = 'commander'


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=100)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def verifie_mission_id(self) -> Self:
        if not self.mission_id[:1] == 'M':
            raise ValueError("Mission ID must start with 'M'")
        return self

    @model_validator(mode='after')
    def verifie_crew_rank(self) -> Self:
        if not any(member.rank.name == 'captain' or
                   member.rank.name == 'commander' for member in self.crew):
            raise ValueError("Must have at least one Commander or Captain")
        return self

    @model_validator(mode='after')
    def verifie_exp_crew(self) -> Self:
        xp = (sum(1 for member in self.crew
                  if member.years_experience >= 5)
              / len(self.crew)) * 100

        if self.duration_days > 365 and not xp >= 50:
            raise ValueError('Long missions (> 365 days)'
                             ' need 50% experienced crew (5+ years)')
        return self

    @model_validator(mode='after')
    def is_crew_active(self) -> Self:
        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")
        return self


def main() -> None:
    rand_int = random.randint(0, len(SPACE_MISSIONS) - 1)
    print("Space Station Data Validation")
    print("========================================")
    print("Valid mission created:")
    space_mission = SpaceMission.model_validate(SPACE_MISSIONS[rand_int])
    print(f"Mission: {space_mission.mission_name}")
    print(f"ID: {space_mission.mission_id}")
    print(f"Destination: {space_mission.destination}")
    print(f"Duration: {space_mission.duration_days} days")
    print(f"Budget: ${space_mission.budget_millions}M")
    print(f"Crew size: {len(space_mission.crew)}")
    for member in space_mission.crew:
        print(f"- {member.name} ({member.rank.name}) - "
              f"{member.specialization}")
    print()
    print("========================================")
    print("Expected validation error:")
    ERROR_SPACE_MISSIONS = {
        'mission_id': 'M2024_TITAN',
        'mission_name': 'Solar Observatory Research Mission',
        'destination': 'Solar Observatory',
        'launch_date': '2024-03-30T00:00:00',
        'duration_days': 600,
        'crew': [
            {
                'member_id': 'CM001',
                'name': 'Sarah Williams',
                'rank': 'captain',
                'age': 43,
                'specialization': 'Mission Command',
                'years_experience': 1,
                'is_active': True
            },
            {
                'member_id': 'CM005',
                'name': 'Maria Jones',
                'rank': 'cadet',
                'age': 55,
                'specialization': 'Research',
                'years_experience': 2,
                'is_active': True
            }
        ],
        'mission_status': 'planned',
        'budget_millions': 2208.1
    }

    try:
        space_mission = SpaceMission.model_validate(ERROR_SPACE_MISSIONS)
    except ValidationError as e:
        print(f"{e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
