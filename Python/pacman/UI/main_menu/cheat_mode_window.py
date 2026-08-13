from typing import Any

import pygame

from .ui_helpers import (
    BLACK,
    GREY,
    WHITE,
    clicked,
    make_main_menu_button,
    make_text,
    wants_to_quit,
)


def render_cheat_mode(window: pygame.Surface, lvl_max: int,
                      settings: dict[str, Any]) -> dict[str, Any]:
    """Render the cheat mode menu."""
    pygame.display.set_caption("Cheat mode")
    font = pygame.font.SysFont("arial", 48)
    clock = pygame.time.Clock()
    center_x = window.get_width() // 2
    done = False

    text_main_menu, rect_main_menu = make_main_menu_button(window, font)
    text_cheat, rect_cheat = make_text(
        font, "Cheat mode", center=(center_x, window.get_height() // 10)
    )

    text_invincibility, rect_invincibility = make_text(
        font,
        "Invincibility",
        center=(center_x, rect_cheat.bottom + 100),
        color=WHITE if settings["invincible"] else GREY,
    )
    text_ghost_freeze, rect_ghost_freeze = make_text(
        font,
        "Ghost Freeze",
        center=(center_x, rect_invincibility.bottom + 50),
        color=WHITE if settings["invincible"] else GREY,
    )

    text_plus = font.render("+", True, WHITE)
    text_minus = font.render("-", True, WHITE)

    text_level, rect_level = make_text(
        font, f"Level {settings["level"] + 1}",
        center=(center_x, rect_ghost_freeze.bottom + 50)
    )
    rect_plus_level = text_plus.get_rect(
        center=(rect_level.right + 50, rect_level.centery))
    rect_minus_level = text_minus.get_rect(
        center=(rect_level.left - 50, rect_level.centery))

    text_lives, rect_lives = make_text(
        font, f"Lives {settings['lives']}",
        center=(center_x, rect_level.bottom + 50)
    )
    rect_plus_lives = text_plus.get_rect(
        center=(rect_lives.right + 50, rect_lives.centery))
    rect_minus_lives = text_minus.get_rect(
        center=(rect_lives.left - 50, rect_lives.centery))
    while not done:
        for event in pygame.event.get():
            if wants_to_quit(event) or clicked(event, rect_main_menu):
                done = True

            elif clicked(event, rect_invincibility):
                settings["invincible"] = not settings["invincible"]
                color = WHITE if settings["invincible"] else GREY
                text_invincibility = font.render("Invincibility", True, color)

            elif clicked(event, rect_ghost_freeze):
                settings["ghost_freeze"] = not settings["ghost_freeze"]
                color = WHITE if settings["ghost_freeze"] else GREY
                text_ghost_freeze = font.render("Ghost Freeze", True, color)

            elif (clicked(event, rect_plus_level)
                  and settings["level"] < lvl_max - 1):
                settings["level"] += 1
                text_level = font.render(
                    f"Level {settings['level'] + 1}", True, WHITE)

            elif clicked(event, rect_minus_level) and settings["level"] > 0:
                settings["level"] -= 1
                text_level = font.render(
                    f"Level {settings['level'] + 1}", True, WHITE)

            elif clicked(event, rect_plus_lives):
                settings["lives"] += 1
                text_lives = font.render(
                    f"Lives {settings['lives']}", True, WHITE)

            elif clicked(event, rect_minus_lives) and settings["lives"] > 3:
                settings["lives"] -= 1
                text_lives = font.render(
                    f"Lives {settings['lives']}", True, WHITE)

        window.fill(BLACK)
        window.blit(text_main_menu, rect_main_menu)
        window.blit(text_cheat, rect_cheat)
        window.blit(text_invincibility, rect_invincibility)
        window.blit(text_ghost_freeze, rect_ghost_freeze)

        window.blit(text_level, rect_level)
        window.blit(text_minus, rect_minus_level)
        window.blit(text_plus, rect_plus_level)

        window.blit(text_lives, rect_lives)
        window.blit(text_minus, rect_minus_lives)
        window.blit(text_plus, rect_plus_lives)

        pygame.display.flip()
        clock.tick(30)

    return settings
