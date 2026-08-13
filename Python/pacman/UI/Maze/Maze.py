from mazegenerator import MazeGenerator


class Cell:
    def __init__(self, x: int, y: int, content: int):
        self.x = x
        self.y = y
        self.content = content
        self.has_pacgum = True if content != 15 else False
        self.has_super_pacgum = False


class Maze:
    def __init__(self, width: int, height: int, seed: int | None = None):
        self.width = width
        self.height = height
        if seed:
            generator = MazeGenerator(size=(width, height), seed=seed)
        else:
            generator = MazeGenerator(size=(width, height))
        self.maze = generator.maze
        self.cases: dict[tuple[int, int], Cell] = {}

        for idx_row, row in enumerate(self.maze):
            for idx_col, item in enumerate(row):
                self.cases[(idx_col, idx_row)] = Cell(idx_col,
                                                      idx_row,
                                                      item)
        super_pacgum_list: list[tuple[int, int]] = [(0, 1),
                                                    (width - 2, 0),
                                                    (1, height - 1),
                                                    (width - 1, height - 2)]
        for items in super_pacgum_list:
            self.cases[(items)].has_pacgum = False
            self.cases[(items)].has_super_pacgum = True
