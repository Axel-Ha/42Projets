import os
import unittest
from unittest.mock import MagicMock, patch

import pygame

from UI.main_menu import menu as menu_module

os.environ["SDL_VIDEODRIVER"] = "dummy"


BUTTON_SPACING = 115


def button_center_y(index: int) -> int:
    """Position of the differents button"""
    return menu_module.SCREEN_HEIGHT // 6 + index * BUTTON_SPACING


class TestMenu(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        self.fake_font = MagicMock(spec=pygame.font.Font)
        self.fake_font.render.side_effect = (
            lambda text, aa, color: pygame.Surface((100, 30))
        )
        self.patches = {
            "sysfont": patch("pygame.font.SysFont",
                             return_value=self.fake_font),
            "clock": patch("pygame.time.Clock", return_value=MagicMock()),
            "level_generator": patch.object(menu_module, "new_level",
                                            return_value="quit"),
            "render_highscores": patch.object(menu_module,
                                              "render_highscores"),
            "render_instruction": patch.object(menu_module,
                                               "render_instruction"),
            "render_cheat_mode": patch.object(menu_module,
                                              "render_cheat_mode"),
            "sys_exit": patch("sys.exit"),
        }
        self.mocks = {name: p.start() for name, p in self.patches.items()}
        for p in self.patches.values():
            self.addCleanup(p.stop)
        self.mock_config = {
            "number_level": 3,
            "level_size": [{"width": 10, "height": 10}],
            "seed": 42,
            "highscore_filename": "scores.json",
            "lives": 3,
            "points_per_pacgum": 10,
            "points_per_super_pacgum": 50,
            "points_per_ghost": 200,
            "level_max_time": 60,
        }

    def run_screen(self, event_batches: list[list[pygame.event.Event]]
                   ) -> None:
        with patch("pygame.event.get", side_effect=event_batches):
            menu_module.menu(self.mock_config)

    def _click_at(self, y: int) -> pygame.event.Event:
        """Mock the click button"""
        return pygame.event.Event(
            pygame.MOUSEBUTTONDOWN,
            button=1,
            pos=(menu_module.SCREEN_WIDTH // 2, y),
        )

    def test_start_game(self) -> None:
        """Test if the level 0 is start"""
        start_click = self._click_at(button_center_y(0))
        self.run_screen([[start_click]])

        self.mocks["level_generator"].assert_called_once()

    def test_leaderboard_screen(self) -> None:
        """Test if leaderboard screen is start"""
        click = self._click_at(button_center_y(1))
        quit_event = pygame.event.Event(pygame.QUIT)
        self.run_screen([[click], [quit_event]])

        self.mocks["render_highscores"].assert_called_once()
        self.mocks["level_generator"].assert_not_called()

    def test_instructions_screen(self) -> None:
        """Test if instructions screen is start"""
        click = self._click_at(button_center_y(2))
        quit_event = pygame.event.Event(pygame.QUIT)
        self.run_screen([[click], [quit_event]])

        self.mocks["render_instruction"].assert_called_once()

    def test_exit_button(self) -> None:
        """Test if exit button close the window"""
        click = self._click_at(button_center_y(4))
        self.run_screen([[click]])

        self.mocks["level_generator"].assert_not_called()
        self.mocks["sys_exit"].assert_called_once()

    def test_escape_key_quits_the_menu(self) -> None:
        """Test if escape button close the window"""
        escape_event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_ESCAPE)
        self.run_screen([[escape_event]])

        self.mocks["level_generator"].assert_not_called()
        self.mocks["sys_exit"].assert_called_once()

    def test_cheat_mode_level_is_used_when_starting_a_game(self) -> None:
        """Test if the cheat mode screen is called
        and return with values """
        self.mocks["render_cheat_mode"].return_value = {
            "invincible": False,
            "ghost_freeze": False,
            "level": 2,
            "player_speed": 0.5,
            "lives": 3,
        }
        cheat_click = self._click_at(button_center_y(3))
        start_click = self._click_at(button_center_y(0))
        self.run_screen([[cheat_click], [start_click]])

        self.mocks["render_cheat_mode"].assert_called_once()

    def test_start_game_returns_to_main_menu(self) -> None:
        """Test returning to main menu after level_generator returns
        'main menu'."""
        self.mocks["level_generator"].return_value = "main menu"
        start_click = self._click_at(button_center_y(0))
        quit_event = pygame.event.Event(pygame.QUIT)

        self.run_screen([[start_click], [quit_event]])

        self.mocks["level_generator"].assert_called_once()
        self.mocks["sys_exit"].assert_called_once()
