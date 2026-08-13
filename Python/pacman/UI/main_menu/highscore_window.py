import pygame

from score import get_highscores

from .ui_helpers import (
    BLACK,
    WHITE,
    clicked,
    make_main_menu_button,
    make_text,
    wants_to_quit,
)


def render_highscores(window: pygame.Surface, filename: str) -> None:
    """Render the leaderboard"""
    pygame.display.set_caption("Highscores")
    font = pygame.font.SysFont("arial", 48)
    clock = pygame.time.Clock()
    center_x = window.get_width() // 2
    done = False

    highscores = get_highscores(filename=filename)

    text_main_menu, rect_main_menu = make_main_menu_button(window, font)
    text_title, rect_title = make_text(
        font, "HIGHSCORES", center=(center_x, window.get_height() // 10)
    )

    score_lines: list[tuple[pygame.Surface, pygame.Rect]] = []
    for i, (name, score) in enumerate(highscores.items()):
        surface = font.render(f"{name} : {score}", True, WHITE)
        rect = surface.get_rect(
            center=(center_x, window.get_height() // 4 + i * 50))
        score_lines.append((surface, rect))

    while not done:
        for event in pygame.event.get():
            if wants_to_quit(event) or clicked(event, rect_main_menu):
                done = True

        window.fill(BLACK)
        window.blit(text_title, rect_title)
        window.blit(text_main_menu, rect_main_menu)
        for surface, rect in score_lines:
            window.blit(surface, rect)

        pygame.display.flip()
        clock.tick(30)
