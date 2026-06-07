import sys

if __name__ == "__main__":
    print("=== Commmand Quest ===")
    length = len(sys.argv)
    print(f"Program name: {sys.argv[0]}")
    if (length == 1):
        print("No arguments provided!")
    else:
        print(f"Arguments received: {length - 1}")
        for i in range(1, length):
            print(f"Argument {i}: {sys.argv[i]}")
    print(f"Total arguments: {length}")
