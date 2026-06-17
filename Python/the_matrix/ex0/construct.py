import sys
import os
import site


def in_virtualenv() -> bool:
    if sys.prefix == sys.base_prefix:
        print("MATRIX STATUS: You're still plugged in")
        print()
        print(f"Current python: {sys.executable}")
        print("Virtual Environnement: None detected")

        print()
        print("Warning: You're in the global environment")
        print("The machines can see everything you install.")
        print()

        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows")
        print()
        print("Then run this progam again")
        return False
    else:
        print("MATRIX STATUS: Welcome to the construct")
        print()
        print(f"Current python: {sys.executable}")
        print(f"Virtual Environnement: {os.path.basename(sys.prefix)}")
        print(f"Environment Path: {sys.prefix}")
        print()
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting"
              " the global system.")
        print()
        print(f"Package installation path: {site.getsitepackages()[-1]}")
        return True


if __name__ == "__main__":
    in_virtualenv()
