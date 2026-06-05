import sys

if __name__ == "__main__":
    if len(sys.argv) == 2:
        print("=== Cyber Archives Recovery ===")
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

            new_file = input("Enter new file name (or empty):")
            if new_file:
                file_to_transform = open(new_file, "w")
                print(f"Saving data to '{new_file}'.")
                file_to_transform.write(new_content)
                file_to_transform.close()
                print(f"Data saved in file '{new_file}'.")
            else:
                print("Not saving data.")

        except FileNotFoundError as e:
            print(f"Error opening file '{sys.argv[1]}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{sys.argv[1]}': {e}")

    else:
        print(f"Usage {sys.argv[0]} <file>")
