import os
import unittest
from UI.Maze.Maze import Maze, Cell
import importlib
pac_man = importlib.import_module("pac-man")
# check_value = pac_man.check_value

os.environ["SDL_VIDEODRIVER"] = "dummy"


class Test_level_Creation(unittest.TestCase):
    """
        Function to test level creation:
            Test with a 10*10 maze with a 42 seed (no random)
            Test if cases content to be between 0 and 15
            Test if walls are correct
    """

    def setUp(self) -> None:
        """
            Setup function to create the maze before each test
        """
        self.width: int | None = 10
        self.height: int | None = 10
        self.seed: int | None = 42
        self.generator: Maze | None = Maze(self.width, self.height, self.seed)
        self.maze: list[list[str]] | None = self.generator.maze
        self.cases: dict[tuple[int, int], Cell] = {}

        if self.maze:
            for idx_row, row in enumerate(self.maze):
                for idx_col, item in enumerate(row):
                    self.cases[(idx_col, idx_row)] = Cell(idx_col,
                                                          idx_row,
                                                          int(item))

    def tearDown(self) -> None:
        """
            Clean up function to clean variable at the end of each test
        """
        self.width = None
        self.height = None
        self.seed = None
        self.maze = None
        self.cases = {}

    def test_cases_content(self) -> None:
        """
            Function to test the content of each test
        """
        if self.maze:
            for ind_row, row in enumerate(self.maze):
                for ind_col, col in enumerate(row):
                    content: int = self.cases[(ind_col, ind_row)].content
                    self.assertTrue(0 <= content <= 15)

    def test_walls(self) -> None:
        """
            Function to test of walls are correct:
                If there is a wall to the right of the cell
                Then a wall should be at the left of the next cell
        """
        if self.maze and self.width and self.height:
            for ind_row, row in enumerate(self.maze):
                for ind_col, col in enumerate(row):
                    # Check if there's an upper wall
                    if (self.cases[(ind_col, ind_row)].content & 1):
                        if ind_row != 0:
                            up_content: int = self.cases[(ind_col,
                                                          ind_row - 1
                                                          )].content
                            self.assertTrue(up_content & 4)

                    # Check if there's a rigth wall
                    if self.cases[(ind_col, ind_row)].content & 2:
                        if ind_col != self.width - 1:
                            right_content: int = self.cases[(ind_col + 1,
                                                             ind_row
                                                             )].content
                            self.assertTrue(right_content & 8)

                    # Check if there's a bottom wall
                    if self.cases[(ind_col, ind_row)].content & 4:
                        if ind_row != self.height - 1:
                            bot_content: int = self.cases[(ind_col,
                                                           ind_row + 1
                                                           )].content
                            self.assertTrue(bot_content & 1)

                    # Check if there's a left wall
                    if self.cases[(ind_col, ind_row)].content & 8:
                        if ind_col != 0:
                            left_content: int = self.cases[(ind_col - 1,
                                                            ind_row
                                                            )].content
                            self.assertTrue(left_content & 2)
