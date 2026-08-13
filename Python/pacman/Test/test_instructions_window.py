import os
import unittest
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.main_menu.instructions_window import render_instruction

os.environ["SDL_VIDEODRIVER"] = "dummy"


class TestInstructionsWindow(unittest.TestCase):
    def setUp(self) -> None:
        """Setup the window and the font"""
        pygame.init()
        pygame.display.set_mode((800, 600))
        self.window = MagicMock(spec=pygame.Surface)
        self.window.get_width.return_value = 800
        self.window.get_height.return_value = 600

        self.fake_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.fake_font)
        font_patcher.start()
        self.addCleanup(font_patcher.stop)

        self.addCleanup(patch("pygame.time.Clock",
                              return_value=MagicMock()).start().stop)

    @patch("UI.main_menu.instructions_window.pygame.event.get")
    def test_renders_all_instruction(self, mock_event_get: MagicMock) -> None:
        """Test if all instruction are display"""
        mock_event_get.return_value = [pygame.event.Event(pygame.QUIT)]
        render_instruction(self.window)
        instructions = [
            "Instruction",
            "Use the arrow key to move freely in the maze",
            "Avoid the ghosts to not lose a life",
            "Walk on the pacgum to increase your score",
            "Walk on superpacgum and for 3 secondes",
            "you will be able to eat a ghost",
            "To win you have to collect all the pacgum",
            "within the time limit",
            "You lose if you don't collect all the pacgum",
            "within the time limit or if you loose your 3 lives"
        ]
        for text in instructions:
            self.fake_font.render.assert_any_call(
                text, True, (WHITE))

    def test_quits_on_quit_event(self) -> None:
        quit_event = pygame.event.Event(pygame.QUIT)
        with patch("pygame.event.get", return_value=[quit_event]):
            render_instruction(self.window)
