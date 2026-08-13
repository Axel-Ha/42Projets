import json
import unittest
from typing import Any
from unittest.mock import mock_open, patch

from score.highscores_manager import get_highscores, set_highscore


class TestHighscore(unittest.TestCase):
    def setUp(self) -> None:
        self.mock_filename = "mock_score.json"
        self.mock_highscores_content = """
            {
                "Axel": 100,
                "Kidax": 20
            }
        """
        self.mock_new_scores_content = ("Joe", 200)

    # Simulate that the file exists
    @patch("pathlib.Path.is_file", return_value=True)
    def test_get_highscores(self, _: Any) -> None:
        """Test reading highscores mocked."""
        with patch(
            "builtins.open",
            new=mock_open(read_data=self.mock_highscores_content),
            create=True,
        ):
            result = get_highscores(self.mock_filename)
            self.assertEqual(result, {"Axel": 100, "Kidax": 20})

    @patch("pathlib.Path.is_file", return_value=False)
    def test_get_highscores_file_not_found(self, _: Any) -> None:
        """Test returning empty dict when file does not exist."""
        result = get_highscores(self.mock_filename)
        self.assertEqual(result, {})

    @patch("pathlib.Path.is_file", return_value=True)
    def test_get_highscores_invalid_json(self, _: Any) -> None:
        """Test returning empty dict when the file is corrupted."""
        with patch(
            "builtins.open",
            new=mock_open(read_data="not valid json"),
            create=True,
        ):
            result = get_highscores(self.mock_filename)
            self.assertEqual(result, {})

    @patch("pathlib.Path.is_file", return_value=True)
    def test_write_highscores(self, _: Any) -> None:
        """Test write highscores in file."""
        with patch(
            "builtins.open",
            new=mock_open(read_data=self.mock_highscores_content),
            create=True,
        ) as mock_file:
            set_highscore(self.mock_filename, self.mock_new_scores_content)

            handle = mock_file()
            handle.write.assert_called_once_with(
                json.dumps(
                    {"Joe": 200, "Axel": 100, "Kidax": 20}, indent=4
                )
            )

    @patch("pathlib.Path.is_file", return_value=True)
    def test_highscores_keeps_best_score_per_player(
        self, _: Any
    ) -> None:
        """Test to keep the best score from the same player"""
        with patch(
            "builtins.open",
            new=mock_open(read_data=self.mock_highscores_content),
            create=True,
        ) as mock_file:
            set_highscore(self.mock_filename, ("Axel", 50))
            handle = mock_file()
            handle.write.assert_called_once_with(
                json.dumps({"Axel": 100, "Kidax": 20}, indent=4)
            )

    @patch("pathlib.Path.is_file", return_value=True)
    def test_write_highscores_10_scores(self, _: Any) -> None:
        """Test to kep the best 10 scores"""
        ten_players = {
            "Joe": 9999,
            "test": 4393,
            "pkpas": 4373,
            "blblbl": 20,
            "Josh": 10,
            "Jos": 10,
            "Jo": 10,
            "J": 10,
            "": 10,
            "c": 10,
        }
        content = json.dumps(ten_players)

        with patch(
            "builtins.open",
            new=mock_open(read_data=content),
            create=True,
        ) as _:
            set_highscore(self.mock_filename, ("player11", 1))
            self.assertNotIn("player11", ten_players)
