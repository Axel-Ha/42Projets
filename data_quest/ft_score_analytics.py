import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    if len(sys.argv) == 1:
        print("No score privided. Usage: python3 ft_score_analytics.py"
              " <score1> <score2> ...")
        sys.exit()

    length = len(sys.argv)
    list_score = []
    for i in range(1, length):
        try:
            list_score.append(int(sys.argv[i]))
        except ValueError:
            print(f"Invalid parameter: '{sys.argv[i]}'")
    if len(list_score) == 0:
        print("No score privided")
        sys.exit()
    print(f"Scores processed: {list_score}")
    print(f"Total player: {len(list_score)}")
    print(f"Total score: {sum(list_score)}")
    print(f"Average score: {sum(list_score) / len(list_score):.1f}")
    print(f"Max score: {max(list_score)}")
    print(f"Low score: {min(list_score)}")
    print(f"Score range: {max(list_score) - min(list_score)}")
