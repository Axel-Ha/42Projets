def input_temperature(temp_str: str) -> int:
    num: int = int(temp_str)
    return num


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print()

    print("Input data is '25'")
    try:
        res: int = input_temperature("25")
        print(f"Temperature is now {res}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    print()

    print("Input data is 'abc'")
    try:
        res_invalid: int = input_temperature("abc")
        print(f"Temperature is now {res_invalid}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    print()
    print("All tests completed - program didn't crash!")


test_temperature()
