import os
import unittest
from typing import Any
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.main_menu.cheat_mode_window import render_cheat_mode

os.environ["SDL_VIDEODRIVER"] = "dummy"


class TestCheatMode(unittest.TestCase):
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

        clock_patcher = patch("pygame.time.Clock", return_value=MagicMock())
        clock_patcher.start()
        self.addCleanup(clock_patcher.stop)
        self.mock_settings = {
            "invincible": False,
            "ghost_freeze": False,
            "level": 0,
            "lives": 3,
        }

    def run_screen(self, event_batches: list[list[pygame.event.Event]]
                   ) -> dict[str, Any]:
        """Run the cheat mode window"""
        with patch("pygame.event.get", side_effect=event_batches):
            return render_cheat_mode(self.window, lvl_max=5,
                                     settings=self.mock_settings)

    def test_quit_returns_default_settings(self) -> None:
        """Test if default settings are returns"""
        quit_event = pygame.event.Event(pygame.QUIT)
        settings = self.run_screen([[quit_event]])
        self.assertEqual(
            settings,
            {
                "invincible": False,
                "ghost_freeze": False,
                "level": 0,
                "lives": 3,
            },
        )

    def test_main_menu_button_closes(self) -> None:
        """Test if main menu button work"""
        click = pygame.event.Event(
            pygame.MOUSEBUTTONDOWN, button=1, pos=(800 // 8, 600 // 10)
        )
        settings = self.run_screen([[click]])
        self.assertEqual(settings["level"], 0)

    def test_invincibility(self) -> None:
        """Test if invicibility is true when clicked"""
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=(400, 185))
        quit_event = pygame.event.Event(pygame.QUIT)
        settings = self.run_screen([[click], [quit_event]])
        self.assertTrue(settings["invincible"])
        self.fake_font.render.assert_any_call("Invincibility", True, WHITE)

    def test_ghost_freeze(self) -> None:
        """Test if ghost freeze is true when clicked"""
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=(400, 260))
        quit_event = pygame.event.Event(pygame.QUIT)
        settings = self.run_screen([[click], [quit_event]])
        self.assertTrue(settings["ghost_freeze"])

    def test_lives_regression_cant_go_under_3(self) -> None:
        """Test if we can't go under 3 when lives buttons are clicked"""
        minus_pos = (300 - 50, 410)
        quit_event = pygame.event.Event(pygame.QUIT)
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=minus_pos)

        settings = self.run_screen([[click], [click],
                                    [click], [click], [quit_event]])
        self.assertEqual(settings["lives"], 3)

    def test_lives_plus_button_increments(self) -> None:
        plus_pos = (500 + 50, 410)
        quit_event = pygame.event.Event(pygame.QUIT)
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=plus_pos)

        settings = self.run_screen([[click], [click], [quit_event]])
        self.assertEqual(settings["lives"], 5)

    def test_level_increment_is_capped_at_lvl_max(self) -> None:
        """Test if level increase is capped at lvl max """
        plus_pos = (500 + 50, 335)
        quit_event = pygame.event.Event(pygame.QUIT)
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=plus_pos)

        settings = self.run_screen([[click]] * 6 + [[quit_event]])
        self.assertEqual(settings["level"], 4)

    def test_level_decrement_cannot_go_below_zero(self) -> None:
        """Test to not go under 0 for levels"""
        minus_pos = (300 - 50, 335)
        quit_event = pygame.event.Event(pygame.QUIT)
        click = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=minus_pos)

        settings = self.run_screen([[click], [click], [quit_event]])
        self.assertEqual(settings["level"], 0)
