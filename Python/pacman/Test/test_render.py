import unittest
from unittest.mock import MagicMock, patch

import pygame
from utils import WHITE, make_fake_font

from UI.level_generator.level_generator import (
    draw_maze,
    infos_screen_left,
    infos_screen_right,
)


class TestMazeRender(unittest.TestCase):
    """
        Test if the draw function works correctly
    """

    def setUp(self) -> None:
        """
            Setup fonction to run before each test
        """
        pygame.init()
        self.surface = pygame.Surface((300, 300))
        self.cell_size: int = 20
        self.mock_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.mock_font)
        font_patcher.start()
        self.level_progression = {
            "first_game": True,
            "current_level": 0,
            "player_lives": 3,
            "player_score": -20,
            "remaining_level": 8
        }

        maze_width_px = 1 * self.cell_size
        maze_height_px = 1 * self.cell_size
        self.offset_x = (self.surface.get_width() - maze_width_px) // 2
        self.offset_y = (self.surface.get_height() - maze_height_px) // 2 - 40

        maze_width_px = 1 * self.cell_size
        maze_height_px = 1 * self.cell_size
        self.offset_x = (self.surface.get_width() - maze_width_px) // 2
        self.offset_y = (self.surface.get_height() - maze_height_px) // 2 - 40

        maze_width_px = 1 * self.cell_size
        maze_height_px = 1 * self.cell_size
        self.offset_x = (self.surface.get_width() - maze_width_px) // 2
        self.offset_y = (self.surface.get_height() - maze_height_px) // 2 - 40

    def test_draw_maze_pixels(self) -> None:
        """
            Function to test if the draw maze function does work
        """
        mock_maze = MagicMock()
        mock_maze.width = 1
        mock_maze.height = 1
        mock_maze.maze = [[1]]

        self.surface.fill((0, 0, 0))

        draw_maze(self.surface,
                  mock_maze,
                  self.cell_size,
                  None,
                  1,
                  self.mock_font,
                  1000,
                  self.level_progression,
                  None)

        pixel_color = self.surface.get_at(
            (self.offset_x + 10, self.offset_y)
        )[:3]
        self.assertEqual(pixel_color, (33, 33, 255))

    def test_pacgum(self) -> None:
        """
            Function to test if pacgums are drawn correctly
        """
        mock_maze = MagicMock()
        mock_maze.width = 1
        mock_maze.height = 1
        mock_maze.maze = [[0]]

        mock_case = MagicMock()
        mock_case.has_pacgum = True
        mock_case.has_super_pacgum = False
        mock_maze.cases = {(0, 0): mock_case}

        self.surface.fill((0, 0, 0))

        draw_maze(self.surface,
                  mock_maze,
                  self.cell_size,
                  None,
                  1,
                  self.mock_font,
                  1000,
                  self.level_progression,
                  None)

        pixel_color = self.surface.get_at(
            (self.offset_x + 10, self.offset_y + 10)
        )[:3]
        self.assertEqual(pixel_color, (240, 240, 240))

    def test_super_pacgum(self) -> None:
        """
            Function to test if super pacgums are drawn correctly
        """
        mock_maze = MagicMock()
        mock_maze.width = 1
        mock_maze.height = 1
        mock_maze.maze = [[0]]

        mock_case = MagicMock()
        mock_case.has_pacgum = False
        mock_case.has_super_pacgum = True
        mock_maze.cases = {(0, 0): mock_case}

        self.surface.fill((0, 0, 0))

        draw_maze(self.surface,
                  mock_maze,
                  self.cell_size,
                  None,
                  1,
                  self.mock_font,
                  1000,
                  self.level_progression,
                  None)

        pixel_color = self.surface.get_at(
            (self.offset_x + 10, self.offset_y + 10)
        )[:3]
        self.assertEqual(pixel_color, (255, 165, 0))


class TestDisplayFunctionsDummy(unittest.TestCase):
    def setUp(self) -> None:
        """
        Setup for infos display's test
        """
        self.window = pygame.display.set_mode((800, 600))
        self.mock_font = make_fake_font()
        font_patcher = patch("pygame.font.SysFont",
                             return_value=self.mock_font)
        font_patcher.start()
        self.dummy_player = MagicMock()
        self.dummy_player.nb_lives = 3
        self.dummy_player.score = 1500

    def test_infos_screen_left(self) -> None:
        """
        Run the function to check if it crashes.
        """
        position = (15, 100)
        text_to_display = f"Lives: {self.dummy_player.nb_lives}"
        infos_screen_left(
            self.window,
            self.mock_font,
            self.dummy_player,
            WHITE,
            position,
            text_to_display
        )

    def test_infos_screen_right(self) -> None:
        """
        Run the function to check if it crashes.
        """
        position = (700, 100)
        text_to_display = "Current level: 1"
        infos_screen_right(
            self.window,
            self.mock_font,
            self.dummy_player,
            WHITE,
            position,
            text_to_display
        )
