from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum
from typing_extensions import Self
from alien_contacts import ALIEN_CONTACTS
import random


class ContactType(Enum):
    radio = 'radio'
    visual = 'visual'
    physical = 'physical'
    telepathic = 'telepathic'


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def verifie_contact(self) -> Self:
        if not self.contact_id[:2] == "AC":
            raise ValueError("Contact ID must start with 'AC'")
        return self

    @model_validator(mode='after')
    def verifie_physical_conctact(self) -> Self:
        if (self.contact_type.name == "physical"
                and not self.is_verified):
            raise ValueError("Physical contact reports"
                             " must be verified")
        return self

    @model_validator(mode='after')
    def verifie_telepathic_conctact(self) -> Self:
        if (self.contact_type.name == "telepathic"
                and not self.witness_count >= 3):
            raise ValueError("Telepathic contact requires"
                             " at least 3 witnesses")

        return self

    @model_validator(mode='after')
    def verifie_signal_strength(self) -> Self:
        if (self.signal_strength > 7.0
                and self.message_received is None):
            raise ValueError("Strong signals (> 7.0) "
                             "should include received messages")
        return self


def main() -> None:
    rand_int = random.randint(0, len(ALIEN_CONTACTS) - 1)
    print("Space Station Data Validation")
    print("========================================")
    print("Valid contact report:")
    alien_contact = AlienContact.model_validate(ALIEN_CONTACTS[rand_int])
    print(f"ID: {alien_contact.contact_id}")
    print(f"Type: {alien_contact.contact_type}")
    print(f"Location: {alien_contact.location}")
    print(f"Signal: {alien_contact.signal_strength}/10")
    print(f"Duration: {alien_contact.duration_minutes} minutes")
    print(f"Witnesses: {alien_contact.witness_count}")
    print(f"Message: {alien_contact.message_received}")
    print()
    print("========================================")
    print("Expected validation error:")
    ERROR_ALIEN_CONTACTS = {
        'contact_id': 'AC_2024_001',
        'timestamp': '2024-01-20T00:00:00',
        'location': 'Atacama Desert, Chile',
        'contact_type': 'telepathic',
        'signal_strength': 9.6,
        'duration_minutes': 99,
        'witness_count': 2,
        'message_received': 'Greetings from Zeta Reticuli',
        'is_verified': False
    }

    try:
        alien_contact = AlienContact.model_validate(ERROR_ALIEN_CONTACTS)
    except ValidationError as e:
        print(f"{e.errors()[0]['msg']}")


if __name__ == "__main__":
    main()
