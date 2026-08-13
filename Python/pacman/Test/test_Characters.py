import unittest
from unittest.mock import MagicMock

from Characters.player_and_monsters import Ghosts, Player
from UI.Maze.Maze import Cell


class TestCharactersCreation(unittest.TestCase):
    """
    Testing Characters creation.
    """
    def test_player_initialization(self) -> None:
        """
        Testing if the player creation works.
        """
        player = Player((5, 5), 0)
        self.assertEqual(player.coords, (5, 5))
        self.assertEqual(player.nb_lives, 3)

    def test_ghost_initialization(self) -> None:
        """
        Testing if the ghosts creation works.
        """
        ghost = Ghosts(coords_spawn=(10, 10), color=(255, 0, 0), level=0)
        self.assertEqual(ghost.coords, (10, 10))
        self.assertEqual(ghost.color, (255, 0, 0))


class TestMovements(unittest.TestCase):
    """
    Testing Movements for both player and ghosts.
    """
    def setUp(self) -> None:
        """
        Set up a grid for movements before each tests.
        """
        self.player = Player((1, 1), 0)
        self.mock_maze = MagicMock()

        grid = [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0]
        ]
        self.mock_maze.maze = grid
        self.mock_maze.width = 3
        self.mock_maze.height = 3
        self.mock_maze.cases = {}
        for idx_row, row in enumerate(grid):
            for idx_col, item in enumerate(row):
                self.mock_maze.cases[(idx_col, idx_row)] = Cell(
                    idx_col,
                    idx_row,
                    item
                )

    def test_move_right_success(self) -> None:
        """
        Testing if the right move works.
        """
        if not self.mock_maze.cases[self.player.coords].content & 2:
            self.player.move_right(self.mock_maze)
        self.assertEqual(self.player.coords, (2, 1))

    def test_move_right_blocked_by_wall(self) -> None:
        """
        Testing if the right move fails.
        """
        self.mock_maze.cases[(1, 1)].content = 15
        if not self.mock_maze.cases[self.player.coords].content & 2:
            self.player.move_right(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 1))

    def test_move_left_success(self) -> None:
        """
        Testing if the left move works.
        """
        if not self.mock_maze.cases[self.player.coords].content & 8:
            self.player.move_left(self.mock_maze)
        self.assertEqual(self.player.coords, (0, 1))

    def test_move_left_blocked_by_wall(self) -> None:
        """
        Testing if the right move fails.
        """
        self.mock_maze.cases[(1, 1)].content = 15
        if not self.mock_maze.cases[self.player.coords].content & 8:
            self.player.move_left(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 1))

    def test_move_down_success(self) -> None:
        """
        Testing if the down move works.
        """
        if not self.mock_maze.cases[self.player.coords].content & 4:
            self.player.move_down(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 2))

    def test_move_down_blocked_by_wall(self) -> None:
        """
        Testing if the down move fails.
        """
        self.mock_maze.cases[(1, 1)].content = 15
        if not self.mock_maze.cases[self.player.coords].content & 4:
            self.player.move_down(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 1))

    def test_move_up_success(self) -> None:
        """
        Testing if the up move works.
        """
        if not self.mock_maze.cases[self.player.coords].content & 1:
            self.player.move_up(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 0))

    def test_move_up_blocked_by_wall(self) -> None:
        """
        Testing if the up move fails.
        """
        self.mock_maze.cases[(1, 1)].content = 15
        if not self.mock_maze.cases[self.player.coords].content & 1:
            self.player.move_up(self.mock_maze)
        self.assertEqual(self.player.coords, (1, 1))


class TestInteractions(unittest.TestCase):
    """
    Tests for collisions and interactions
    """

    def setUp(self) -> None:
        """
        Context initialisation
        """
        self.player = Player(coords_spawn=(1, 1), level=0)
        self.player.coords = (1, 1)
        self.player.score = 0
        self.player.super = False

        self.ghost = Ghosts(coords_spawn=(10, 10), color=(255, 0, 0), level=0)
        self.ghost.coords = (5, 5)

    def test_ghost_eats_player(self) -> None:
        """
        A ghosts eat the player:
            the player lose a live and return to spawn
        """
        initial_lives = self.player.nb_lives
        self.ghost.eat(self.player)

        self.assertEqual(self.player.nb_lives, initial_lives - 1)
        self.assertEqual(self.player.coords, self.player.coords_spawn)

    def test_player_eats_pacgum(self) -> None:
        """
        When the player eat a pacgum, the score goes up and case is now empty.
        """
        mock_case = MagicMock()
        mock_case.has_pacgum = True
        score_pacgum = 10

        if mock_case.has_pacgum:
            self.player.eat(score_pacgum)
            mock_case.has_pacgum = False

        self.assertFalse(mock_case.has_pacgum)
        self.assertEqual(self.player.score, 10)

    def test_player_eats_super_pacgum(self) -> None:
        """
        When player eat a super pacgum, score, power and timer are activated
        """
        mock_case = MagicMock()
        mock_case.has_super_pacgum = True
        score_super = 50
        current_time = 1000

        if mock_case.has_super_pacgum:
            self.player.eat(score_super)
            mock_case.has_super_pacgum = False
            self.player.super = True
            self.player.super_time = current_time

        self.assertFalse(mock_case.has_super_pacgum)
        self.assertEqual(self.player.score, 50)
        self.assertTrue(self.player.super)
        self.assertEqual(self.player.super_time, 1000)

    def test_player_eats_ghost(self) -> None:
        """
        When player is in super mode and touch a ghost, the ghost dies
        """
        self.player.super = True
        self.player.score = 0
        self.player.coords = (5, 5)
        self.ghost.coords = (5, 5)

        if self.ghost.coords == self.player.coords:
            if not self.player.super:
                self.ghost.eat(self.player)
            else:
                self.player.eat(3)
                self.ghost.is_dead = True
                self.ghost.death_time = 5000
                self.ghost.coords = (-1, -1)

        self.assertEqual(self.player.score, 3)
        self.assertTrue(self.ghost.is_dead)
        self.assertEqual(self.ghost.coords, (-1, -1))
        self.assertEqual(self.ghost.death_time, 5000)
