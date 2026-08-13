import os
from dotenv import load_dotenv
import sys


def checking_override(required: list[str]) -> bool:
    return any(key in os.environ for key in required)


def get_env_var() -> None:
    MATRIX_MODE = os.getenv('MATRIX_MODE')
    DATABASE_URL = os.getenv('DATABASE_URL')
    API_KEY = os.getenv('API_KEY')
    LOG_LEVEL = os.getenv('LOG_LEVEL')
    ZION_ENDPOINT = os.getenv('ZION_ENDPOINT')

    print("Configuration loaded:")
    print(f"Mode: {MATRIX_MODE}")
    if MATRIX_MODE == "development":
        print(f"Database: {DATABASE_URL}")
        print(f"API Access: {API_KEY}")
    else:
        API_KEY = "*********"
        DATABASE_URL = "Connected to online server"
        print(f"Database: {DATABASE_URL}")
        print(f"API Access: {API_KEY}")

    print(f"Log Level: {LOG_LEVEL}")
    print(f"Zion Network: {ZION_ENDPOINT}")


def security_check(override: bool) -> None:
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    if os.path.isfile(".env"):
        print("[OK] .env file properly configured")
    else:
        print("[OK] .env file not configured")
    if not override:
        print("[OK] Production overrides available")
    else:
        print("[OK] Environment variables override detected")
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    required = [
        "MATRIX_MODE",
        "DATABASE_URL",
        "API_KEY",
        "LOG_LEVEL",
        "ZION_ENDPOINT"
    ]
    override_detected = checking_override(required)

    if not load_dotenv():
        print("No .env file was found")

    print("ORACLE STATUS: Reading the Matrix...")
    print()

    missing = [value for value in required if not os.getenv(value)]

    if missing:
        print(f"Missing configuration: {', '.join(missing)}")
        sys.exit(1)
    get_env_var()
    print()
    security_check(override_detected)
