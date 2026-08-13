from unittest.mock import MagicMock

import pygame

FONT_SIZE = (200, 50)
WHITE = (255, 255, 255)


def make_fake_font() -> MagicMock:
    """Mock a font"""
    fake_font = MagicMock(spec=pygame.font.Font)
    fake_font.render.side_effect = lambda text, aa, color: pygame.Surface(
        FONT_SIZE)
    return fake_font
