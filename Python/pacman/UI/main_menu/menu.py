import sys
from typing import Any

import pygame

from ..level_generator.level_generator import new_level
from .cheat_mode_window import render_cheat_mode
from .highscore_window import render_highscores
from .instructions_window import render_instruction
from .ui_helpers import BLACK, clicked, make_text, wants_to_quit

SCREEN_WIDTH = 1300
SCREEN_HEIGHT = 1000


def menu(config: dict[str, Any]) -> None:
    """Render the main menu"""
    cheat_settings = {
        "invincible": False,
        "ghost_freeze": False,
        "level": 0,
        "lives": config["lives"],
    }
    level_progression = {
        "first_game": True,
        "current_level": 0,
        "player_lives": config["lives"],
        "player_score": -20,
        "remaining_level": config["level_size"]
    }

    infos: tuple[int, int, int, int, int, int] = (
        level_progression["player_lives"],
        config["points_per_pacgum"],
        config["points_per_super_pacgum"],
        config["points_per_ghost"],
        config["level_max_time"],
        config["number_level"])
    pygame.init()
    window = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Main menu")
    pygame.font.init()
    font = pygame.font.SysFont("arial", 48)

    center_x = window.get_width() // 2
    clock = pygame.time.Clock()
    running: bool = True
    text_start_game, rect_start_game = make_text(
        font, "Start game", center=(center_x, window.get_height() // 6)
    )
    text_leaderboard, rect_leaderboard = make_text(
        font, "Leaderboard", center=(center_x, rect_start_game.bottom + 100)
    )
    text_instructions, rect_instructions = make_text(
        font, "Instructions", center=(center_x, rect_leaderboard.bottom + 100)
    )
    text_cheat_mode, rect_cheat_mode = make_text(
        font, "Cheat mode", center=(center_x, rect_instructions.bottom + 100)
    )
    text_exit, rect_exit = make_text(
        font, "Exit game", center=(center_x, rect_cheat_mode.bottom + 100)
    )

    while running:
        for event in pygame.event.get():
            if wants_to_quit(event):
                running = False
            elif clicked(event, rect_start_game):
                start_level = int(cheat_settings["level"])
                level_progression["player_lives"] = int(
                    cheat_settings["lives"])
                level_progression["player_score"] = -20
                level_progression["remaining_level"] = config["level_size"]
                if start_level == 0:
                    level_progression["first_game"] = True
                    level_progression["current_level"] = 0
                else:
                    level_progression["first_game"] = False
                    level_progression["current_level"] = start_level

                res = new_level(level_progression, window, infos,
                                config["highscore_filename"], cheat_settings,
                                config["seed"]
                                )
                if res == "quit":
                    running = False
                if res == "main menu":
                    cheat_settings = {
                        "invincible": False,
                        "ghost_freeze": False,
                        "level": 0,
                        "lives": config["lives"],
                    }
            elif clicked(event, rect_leaderboard):
                render_highscores(window, config["highscore_filename"])
            elif clicked(event, rect_instructions):
                render_instruction(window)
            elif clicked(event, rect_cheat_mode):
                cheat_settings = render_cheat_mode(
                    window, config["number_level"], cheat_settings)
            elif clicked(event, rect_exit):
                running = False

        window.fill(BLACK)

        window.blit(text_start_game, rect_start_game)
        window.blit(text_leaderboard, rect_leaderboard)
        window.blit(text_instructions, rect_instructions)
        window.blit(text_cheat_mode, rect_cheat_mode)
        window.blit(text_exit, rect_exit)

        pygame.display.flip()
        clock.tick(30)

    pygame.quit()
    sys.exit()
