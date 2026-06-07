def ft_print_harvest(days: int, max_days: int) -> None:
    if days != max_days:
        print("Days", days)
        ft_print_harvest(days + 1, max_days)
    else:
        print("Days", days)
        print("Harvest time!")


def ft_count_harvest_recursive() -> None:
    harvest = int(input("Days until harvest: "))
    ft_print_harvest(1, harvest)
