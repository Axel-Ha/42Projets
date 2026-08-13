import pygame

from .ui_helpers import render_static_screen


def render_instruction(window: pygame.Surface) -> None:
    """Render the instruction window"""
    font = pygame.font.SysFont("arial", 48)
    lines = [
        ("Instruction", 0),
        ("Use the arrow key to move freely in the maze", 100),
        ("Avoid the ghosts to not lose a life", 70),
        ("Walk on the pacgum to increase your score", 70),
        ("Walk on superpacgum and for 3 secondes", 70),
        ("you will be able to eat a ghost", 30),
        ("To win you have to collect all the pacgum", 70),
        ("within the time limit", 30),
        ("You lose if you don't collect all the pacgum", 70),
        ("within the time limit or if you loose your 3 lives", 30),
    ]

    render_static_screen(window, "Instruction", lines, font)
