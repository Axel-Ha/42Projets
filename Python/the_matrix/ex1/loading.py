from importlib.metadata import version, PackageNotFoundError
import sys


def checkdependencies() -> bool:
    dependencies = {'pandas': 'Data manipulation', 'numpy': 'Numerical computation',
                    'requests': 'Network access', 'matplotlib': 'Visualization'}
    flag = True
    for key, value in dependencies.items():
        try:
            print(f"[OK] {key} ({version(key)}) - {value}")
        except PackageNotFoundError as e:
            print(f"Caught PackageNotFoundError: {e} "
                  f"to install the dependence use the command\n"
                  f"pip install -r requirements.txt\n"
                  f"or poetry install")
            flag = False
    return flag

if __name__ == "__main__":
    print("LOADIN STATUS: Loading programs...")
    if not checkdependencies():
        sys.exit(1)
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt
    a = np.random.randint(0, 100, 50)
    b = np.random.randint(0, 100, 50)
    data = pd.DataFrame({"X": a, "Y": b}).plot(x='X', y='Y')
    fig, ax = plt.subplots()
    ax.scatter(data["X"], data["Y"])
    ax.set_title("title")
    ax.set_xlabel("X Axis")
    ax.set_ylabel("Y Axis")
    fig.savefig("matrix_analysis.png")