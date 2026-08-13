import pygame

WHITE = (255, 255, 255)
GREY = (137, 137, 137)
BLACK = (0, 0, 0)


def make_text(
    font: pygame.font.Font,
    text: str,
    center: tuple[int, int],
    color: tuple[int, int, int] = WHITE,
) -> tuple[pygame.Surface, pygame.Rect]:
    surface = font.render(text, True, color)
    rect = surface.get_rect(center=center)
    return surface, rect


def make_main_menu_button(
    window: pygame.Surface, font: pygame.font.Font
) -> tuple[pygame.Surface, pygame.Rect]:
    """Put the Button 'Main menu'."""
    return make_text(
        font,
        "Main menu",
        center=(window.get_width() // 8, window.get_height() // 10),
    )


def wants_to_quit(event: pygame.event.Event) -> bool:
    """True user close the window or press Esc."""
    return event.type == pygame.QUIT or (
        event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE
    )


def clicked(event: pygame.event.Event, rect: pygame.Rect) -> bool:
    """True if `rect` is clicked."""
    return (
        event.type == pygame.MOUSEBUTTONDOWN
        and event.button == 1
        and rect.collidepoint(event.pos)
    )


def render_static_screen(
    window: pygame.Surface,
    caption: str,
    lines: list[tuple[str, int]],
    font: pygame.font.Font,
) -> None:
    """Render the static informations"""
    pygame.display.set_caption(caption)
    clock = pygame.time.Clock()
    center_x = window.get_width() // 2
    done = False

    text_main_menu, rect_main_menu = make_main_menu_button(window, font)

    rendered: list[tuple[pygame.Surface, pygame.Rect]] = []
    y = window.get_height() // 10
    prev_bottom: int | None = None
    for text, gap in lines:
        if prev_bottom is not None:
            y = prev_bottom + gap
        surface = font.render(text, True, WHITE)
        rect = surface.get_rect(center=(center_x, y))
        rendered.append((surface, rect))
        prev_bottom = rect.bottom

    while not done:
        for event in pygame.event.get():
            if wants_to_quit(event) or clicked(event, rect_main_menu):
                done = True

        window.fill(BLACK)
        window.blit(text_main_menu, rect_main_menu)
        for surface, rect in rendered:
            window.blit(surface, rect)

        pygame.display.flip()
        clock.tick(30)
