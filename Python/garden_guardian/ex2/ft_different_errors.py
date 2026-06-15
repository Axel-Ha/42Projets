def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        try:
            x = int("abc")
        except ValueError as e:
            print(f"Caught ValueError: {e}")
    elif operation_number == 1:
        try:
            x = 10 / 0
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
    elif operation_number == 2:
        try:
            x = open("/non/existent/file")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
    elif operation_number == 3:
        try:
            a = "abc"
            x = 2
            a = a + x
        except TypeError as e:
            print(f"Caught TypeError: {e}")
    else:
        print("Operation completed successfully")


def test_error_types() -> None:
    print("=== Garden Temperature ===")
    print("Testion operation 0...")
    garden_operations(0)
    print("Testion operation 1...")
    garden_operations(1)
    print("Testion operation 2...")
    garden_operations(2)
    print("Testion operation 3...")
    garden_operations(3)
    print("Testion operation 4...")
    garden_operations(4)
    print()
    print("ALl error types tested successfully")


test_error_types()
