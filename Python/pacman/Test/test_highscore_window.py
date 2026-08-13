import os
import unittest
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.main_menu.highscore_window import render_highscores

os.environ["SDL_VIDEODRIVER"] = "dummy"


class TestHighscoreWindow(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        self.window = MagicMock(spec=pygame.Surface)
        self.window.get_width.return_value = 800
        self.window.get_height.return_value = 600
        self.mock_filename = "mock_score.json"

        self.fake_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.fake_font)
        font_patcher.start()

        patch("UI.main_menu.highscore_window.pygame.display.flip").start()
        patch("UI.main_menu.highscore_window.pygame.quit").start()
        patch("UI.main_menu.highscore_window.exit").start()
        self.addCleanup(patch.stopall)

    @patch("UI.main_menu.highscore_window.get_highscores")
    @patch("UI.main_menu.highscore_window.pygame.event.get")
    def test_displays_scores_content(
        self, mock_event_get: MagicMock, mock_get_highscores: MagicMock
    ) -> None:
        """Test scores are display"""
        mock_get_highscores.return_value = {"Joe": 9999, "test": 4393}
        mock_event_get.return_value = [pygame.event.Event(pygame.QUIT)]

        render_highscores(self.window, self.mock_filename)

        self.fake_font.render.assert_any_call(
            "HIGHSCORES", True, (WHITE))
        self.fake_font.render.assert_any_call(
            "Main menu", True, (WHITE))
        self.fake_font.render.assert_any_call(
            "Joe : 9999", True, (WHITE))
        self.fake_font.render.assert_any_call(
            "test : 4393", True, (WHITE))

    @patch("UI.main_menu.highscore_window.get_highscores")
    @patch("UI.main_menu.highscore_window.pygame.event.get")
    def test_render_no_scores(
        self, mock_event_get: MagicMock, mock_get_highscores: MagicMock
    ) -> None:
        """Test no scores are display"""
        mock_get_highscores.return_value = {}
        mock_event_get.return_value = [pygame.event.Event(pygame.QUIT)]

        render_highscores(self.window, self.mock_filename)

    def test_quits_on_escape_key(self) -> None:
        escape_event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_ESCAPE)
        with patch("pygame.event.get", return_value=[escape_event]):
            render_highscores(self.window, "mock.json")

    def test_quits_main_menu_button_clicked(self) -> None:
        click = pygame.event.Event(
            pygame.MOUSEBUTTONDOWN, button=1, pos=(800 // 8, 600 // 10)
        )
        with patch("pygame.event.get", return_value=[click]):
            render_highscores(self.window, "mock.json")
