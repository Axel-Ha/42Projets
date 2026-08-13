import os
import unittest
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.game_over_visual import game_over

os.environ["SDL_VIDEODRIVER"] = "dummy"


class TestGameOverRender(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        self.window = MagicMock(spec=pygame.Surface)
        self.window.get_width.return_value = 800
        self.window.get_height.return_value = 600

        self.font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont", return_value=self.font)
        font_patcher.start()
        self.addCleanup(font_patcher.stop)

        self.mock_score = 999
        self.mock_file = "mock_file.json"

        for target in (
            "UI.game_over_visual.pygame.draw.rect",
            "UI.game_over_visual.pygame.display.flip",
            "UI.game_over_visual.pygame.quit",
            "sys.exit",
        ):
            patcher = patch(target)
            patcher.start()
            self.addCleanup(patcher.stop)

    @patch("UI.game_over_visual.pygame.event.get")
    def test_game_over_displays_text(self, mock_event_get: MagicMock) -> None:
        """Test display GAME OVER text."""
        mock_event_get.side_effect = [[], [pygame.event.Event(pygame.QUIT)]]

        game_over(self.window, self.font, False,
                  self.mock_file, self.mock_score)

        self.font.render.assert_any_call("GAME OVER", True, WHITE)
        self.window.blit.assert_called()

    @patch("UI.game_over_visual.pygame.event.get")
    def test_game_over_win_displays_congrats(
        self, mock_event_get: MagicMock
    ) -> None:
        """Test display CONGRATULATION text."""
        mock_event_get.side_effect = [[], [pygame.event.Event(pygame.QUIT)]]

        game_over(self.window, self.font, True,
                  self.mock_file, self.mock_score)

        self.font.render.assert_any_call("CONGRATULATION", True, WHITE)

    @patch("UI.game_over_visual.set_highscore")
    @patch("UI.game_over_visual.pygame.event.get")
    def test_enter_key_saves_highscore(
        self, mock_event_get: MagicMock, mock_set_highscore: MagicMock
    ) -> None:
        """Test if key enter pressed, the score is saved"""
        enter_event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_RETURN)
        mock_event_get.side_effect = [
            [enter_event],
            [pygame.event.Event(pygame.QUIT)],
        ]

        game_over(self.window, self.font, False,
                  self.mock_file, self.mock_score)

        mock_set_highscore.assert_called_once_with(
            self.mock_file, ("Joe", self.mock_score)
        )

    @patch("UI.game_over_visual.pygame.event.get")
    def test_escape_key_closes_window(self, mock_event_get: MagicMock) -> None:
        escape_event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_ESCAPE)
        mock_event_get.return_value = [escape_event]

        game_over(self.window, self.font, False,
                  self.mock_file, self.mock_score)

    @patch("sys.exit")
    @patch("UI.game_over_visual.pygame.quit")
    @patch("UI.game_over_visual.pygame.display.flip")
    @patch("UI.game_over_visual.pygame.draw.rect")
    @patch("UI.game_over_visual.pygame.event.get")
    def test_add_character(
        self,
        mock_event_get: MagicMock,
        mock_draw_rect: MagicMock,
        mock_flip: MagicMock,
        mock_quit: MagicMock,
        mock_exit: MagicMock,
    ) -> None:
        """Test to add character"""
        key_a = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_a, unicode="A")
        quit_event = pygame.event.Event(pygame.QUIT)
        mock_event_get.side_effect = [[key_a], [quit_event]]

        with patch("UI.game_over_visual.set_highscore"):
            game_over(self.window, self.font, False,
                      self.mock_file, self.mock_score)

        self.font.render.assert_any_call("JoeA", True, WHITE)

    @patch("sys.exit")
    @patch("UI.game_over_visual.pygame.quit")
    @patch("UI.game_over_visual.pygame.display.flip")
    @patch("UI.game_over_visual.pygame.draw.rect")
    @patch("UI.game_over_visual.pygame.event.get")
    def test_backspace_removes_character(
        self,
        mock_event_get: MagicMock,
        mock_draw_rect: MagicMock,
        mock_flip: MagicMock,
        mock_quit: MagicMock,
        mock_exit: MagicMock,
    ) -> None:
        """Test to see if backspace removes character"""
        backspace = pygame.event.Event(
            pygame.KEYDOWN, key=pygame.K_BACKSPACE, unicode=""
        )
        quit_event = pygame.event.Event(pygame.QUIT)
        mock_event_get.side_effect = [[backspace], [quit_event]]

        with patch("UI.game_over_visual.set_highscore"):
            game_over(self.window, self.font, False,
                      self.mock_file, self.mock_score)

        self.font.render.assert_any_call("Jo", True, WHITE)

    @patch("sys.exit")
    @patch("UI.game_over_visual.pygame.quit")
    @patch("UI.game_over_visual.pygame.display.flip")
    @patch("UI.game_over_visual.pygame.draw.rect")
    @patch("UI.game_over_visual.pygame.event.get")
    def test_limit_character_nickname(
        self,
        mock_event_get: MagicMock,
        mock_draw_rect: MagicMock,
        mock_flip: MagicMock,
        mock_quit: MagicMock,
        mock_exit: MagicMock,
    ) -> None:
        """Test nickname is limit to 10"""
        key_a = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_a, unicode="A")
        quit_event = pygame.event.Event(pygame.QUIT)
        mock_event_get.side_effect = [[key_a] * 10, [quit_event]]

        with patch("UI.game_over_visual.set_highscore"):
            game_over(self.window, self.font, False,
                      self.mock_file, self.mock_score)

        self.font.render.assert_any_call("JoeAAAAAAA", True, WHITE)
