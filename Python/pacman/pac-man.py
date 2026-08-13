from parsing import load_game_config
from UI import menu

if __name__ == '__main__':
    menu(config=load_game_config("config.json"))
