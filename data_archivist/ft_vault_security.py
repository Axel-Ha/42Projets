def secure_archive(file_name: str, action: str,
                   string="") -> tuple[True | False, str]:

    if action == "read":
        try:
            with open(file_name, "r") as file:
                content = file.read()
                return True, content
        except (FileNotFoundError, PermissionError) as e:
            return False, str(e)

    if action == "write":
        try:
            with open(file_name, "w") as file:
                file.write(string)
                return True, string
        except (FileNotFoundError, PermissionError) as e:
            return False, str(e)

if __name__ == "__main__":
    print("=== Cyber Archives Security ===")
    print()

    print("Using 'secure_archive' to read a nonexistent file:")
    print(secure_archive("not.txt", "read"))
    print()

    print("Using 'secure_archive' to read an inaccessible file:")
    print(secure_archive("/etc/shadow", "read"))
    print()

    print("Using 'secure_archive' to read a regular file:")
    print(secure_archive("test.txt", "read"))
    print()

    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("test.txt", "write", "New content"))
