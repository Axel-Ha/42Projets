import sys

if __name__ == "__main__":
    if len(sys.argv) == 2:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{sys.argv[1]}'")
        try:
            file = open(sys.argv[1], "r")
            content = file.read()

            print("---\n")
            print(content)
            print("\n---")
            file.close()
            print(f"File '{sys.argv[1]}' closed.")

            print("\nTransform data: ")
            print("---\n")

            content_read = content.split("\n")
            new_line = [(line + "#") for line in content_read]
            new_content = "\n".join(new_line)
            new_content += "\n"
            print(new_content)
            print("\n---")

            sys.stdout.write("Enter new file name (or empty):")
            sys.stdout.flush()
            new_file = sys.stdin.readline()
            new_file = new_file.rstrip("\n")
            if new_file:
                print(f"Saving data to '{new_file}'.")
                try:
                    file_to_transform = open(new_file, "w")
                    file_to_transform.write(new_content)
                    file_to_transform.close()
                    print(f"Data saved in file '{new_file}'.")
                except PermissionError as e:
                    sys.stderr.write(f"[STDERR] Error "
                                     f"opening file '{sys.argv[1]}': {e}\n")
                    print("Data not saved")
            else:
                print("Not saving data.")

        except (FileNotFoundError, PermissionError) as e:
            sys.stderr.write(f"[STDERR] Error "
                             f"opening file '{sys.argv[1]}': {e}\n")
    else:
        print(f"Usage {sys.argv[0]} <file>")
