import os
import unittest
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.main_menu.ui_helpers import (
    clicked,
    make_main_menu_button,
    make_text,
    render_static_screen,
    wants_to_quit,
)

os.environ["SDL_VIDEODRIVER"] = "dummy"


class TestMakeText(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        self.mock_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.mock_font)
        font_patcher.start()

    def test_make_text_renders_with_given_color(self) -> None:
        _, rect = make_text(self.mock_font, "Hello",
                            center=(50, 60), color=(1, 2, 3))
        self.mock_font.render.assert_called_once_with("Hello", True, (1, 2, 3))
        self.assertEqual(rect.center, (50, 60))

    def test_make_text_defaults_to_white(self) -> None:
        make_text(self.mock_font, "Hello", center=(0, 0))
        self.mock_font.render.assert_called_once_with("Hello", True, WHITE)


class TestMakeMainMenuButton(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        self.window = MagicMock(spec=pygame.Surface)
        self.window.get_width.return_value = 800
        self.window.get_height.return_value = 600
        self.mock_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.mock_font)
        font_patcher.start()

    def test_button_is_positioned_from_window_size(self) -> None:
        """Test if main menu button is correctly positioned """
        _, rect = make_main_menu_button(self.window, self.mock_font)
        self.mock_font.render.assert_called_once_with("Main menu", True, WHITE)
        self.assertEqual(rect.center, (800 // 8, 600 // 10))


class TestWantsToQuit(unittest.TestCase):
    def test_quit_event(self) -> None:
        self.assertTrue(wants_to_quit(pygame.event.Event(pygame.QUIT)))

    def test_escape_key(self) -> None:
        event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_ESCAPE)
        self.assertTrue(wants_to_quit(event))

    def test_other_key_is_ignored(self) -> None:
        event = pygame.event.Event(pygame.KEYDOWN, key=pygame.K_a)
        self.assertFalse(wants_to_quit(event))


class TestClicked(unittest.TestCase):
    def setUp(self) -> None:
        self.rect = pygame.Rect(0, 0, 100, 50)

    def test_click_inside_rect(self) -> None:
        event = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=(10, 10))
        self.assertTrue(clicked(event, self.rect))

    def test_click_outside_rect(self) -> None:
        event = pygame.event.Event(pygame.MOUSEBUTTONDOWN,
                                   button=1, pos=(500, 500))
        self.assertFalse(clicked(event, self.rect))


class TestRenderStaticScreen(unittest.TestCase):
    def setUp(self) -> None:
        pygame.init()
        pygame.display.set_mode((800, 600))
        self.window = MagicMock(spec=pygame.Surface)
        self.window.get_width.return_value = 800
        self.window.get_height.return_value = 600
        self.mock_font = MagicMock(spec=pygame.font.Font)
        self.mock_font.render.return_value = pygame.Surface((100, 30))

    def test_quit_main_menu_button_is_clicked(self) -> None:
        click = pygame.event.Event(
            pygame.MOUSEBUTTONDOWN, button=1, pos=(800 // 8, 600 // 10)
        )
        with patch("pygame.event.get", return_value=[click]), \
                patch("pygame.time.Clock", return_value=MagicMock()):
            render_static_screen(self.window,
                                 "caption", [("Line", 0)], self.mock_font)
