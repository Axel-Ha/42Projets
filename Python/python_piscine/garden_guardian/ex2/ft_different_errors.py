def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        x = 10 / 0
    elif operation_number == 2:
        x = open("/non/existent/file")
    elif operation_number == 3:
        a = "abc"
        x = 2
        a = a + x
    else:
        print("Operation completed successfully")


def test_error_types() -> None:
    print("=== Garden Temperature ===")
    print("Testion operation 0...")
    try:
        garden_operations(0)
    except (ValueError, ZeroDivisionError,
            FileNotFoundError, TypeError) as e:
        print(f"Caught {e.__class__.__name__}: {e}")
    print("Testion operation 1...")
    try:
        garden_operations(1)
    except (ValueError, ZeroDivisionError,
            FileNotFoundError, TypeError) as e:
        print(f"Caught {e.__class__.__name__}: {e}")

    print("Testion operation 2...")
    try:
        garden_operations(2)
    except (ValueError, ZeroDivisionError,
            FileNotFoundError, TypeError) as e:
        print(f"Caught {e.__class__.__name__}: {e}")

    print("Testion operation 3...")
    try:
        garden_operations(3)
    except (ValueError, ZeroDivisionError,
            FileNotFoundError, TypeError) as e:
        print(f"Caught {e.__class__.__name__}: {e}")

    print("Testion operation 4...")
    garden_operations(4)
    print()
    print("All error types tested successfully")


test_error_types()
