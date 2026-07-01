from importlib.metadata import version, PackageNotFoundError
import sys


def check_dependencies() -> bool:
    dependencies = {'pandas': 'Data manipulation',
                    'numpy': 'Numerical computation',
                    'requests': 'Network access',
                    'matplotlib': 'Visualization'}
    flag = True
    for key, value in dependencies.items():
        try:
            print(f"[OK] {key} ({version(key)}) - {value}")
        except PackageNotFoundError as e:
            print(f"Caught PackageNotFoundError: {e}.\n"
                  f"To install the dependence use the command\n"
                  f"pip install -r requirements.txt\n"
                  f"or poetry install\n")
            flag = False
    return flag


def comparaison_package_versions() -> None:
    requiredversion = {'pandas': '3.0.3',
                       'numpy': '2.4.6',
                       'requests': '2.34.2',
                       'matplotlib': '3.11.0'}
    for name, required in requiredversion.items():
        print(f"version installed : {name} ({version(name)})\n"
              f"version required : {name} ({required})\n")


def show_package_managers() -> None:
    print("[PIP]  Requirements file: requirements.txt")
    print("[PIP]  Install command: pip install -r requirements.txt")
    print("[PIP]  No lockfile — versions not guaranteed")
    print()
    print("[POETRY]  Config file: pyproject.toml")
    print("[POETRY]  Install command: poetry install")
    print("[POETRY]  Lockfile: poetry.lock — versions guaranteed")


if __name__ == "__main__":
    print("LOADIN STATUS: Loading programs...")
    print()
    if not check_dependencies():
        sys.exit(1)
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print("Analyzing Matrix data...")
    a = np.random.randint(0, 10, 10)
    b = np.random.randint(0, 10, 10)
    print("Processing 1000 data points...")
    data = pd.DataFrame({"X": a, "Y": b})
    fig, ax = plt.subplots()
    data.plot(ax=ax, x='X', y='Y', kind="scatter")
    ax.set_title("title")
    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    print("Generating visualization...")
    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")
    fig.savefig("matrix_analysis.png")

    print()
    comparaison_package_versions()
    print()
    show_package_managers()
