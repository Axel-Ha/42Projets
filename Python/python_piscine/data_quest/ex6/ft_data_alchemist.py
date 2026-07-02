import random
if __name__ == "__main__":
    players = ["Alice", "bob", "Charlie", "dylan",
               "Emma", "Gregory", "john", "kevin", "Liam"]
    second_list = [player.capitalize() for player in players]
    score_dict = {player.capitalize(): random.randint(0, 1000)
                  for player in players}
    capitalize_list = [player for player in players if player[0].isupper()]

    print(f"Initial list of players: {players}")
    print(f"New list with all names capitalized: "
          f"{second_list}")
    print(f"New list of capitalized names only: "
          f"{capitalize_list}")

    print(f"Score dict: {score_dict}")
    score = [score_dict[name] for name in score_dict]
    avg = sum(score) / len(score)
    print(f"Score average is : {round(avg, 2)}")
    high_score = {player: score_dict[player]
                  for player in score_dict if score_dict[player] > avg}
    print(f"High score : {high_score}")
