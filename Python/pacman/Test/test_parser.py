import unittest
# import unittest.mock
from unittest.mock import mock_open, patch
from parsing.parser import (
    load_json_remove_comments,
    validate_level_size,
    validate_int_field,
    load_game_config,
)


class TestConfigParser(unittest.TestCase):
    def setUp(self) -> None:
        self.mock_filename = "fake_config.json"
        self.mock_json_content = """
            {
                # Commentaire sur les pacgums
                "lives": 3
            }
        """

    def test_load_json_remove_comments_valid(self) -> None:
        """Test parsing with a mock JSON file"""
        with patch(
            'builtins.open',
            new=mock_open(read_data=self.mock_json_content),
            create=True
        ):
            mock_result = load_json_remove_comments(self.mock_filename)
            self.assertEqual(mock_result, {
                             "lives": 3})

    def test_file_not_found(self) -> None:
        """Test if file not found, an empty dict is returned"""
        data = load_json_remove_comments("none_file.json")
        self.assertEqual(data, {})

    def test_level_size_valid(self) -> None:
        """Test validation a correct level size"""
        width, height, flag = validate_level_size({"width": 10, "height": 10})
        self.assertEqual(width, 10)
        self.assertEqual(height, 10)
        self.assertFalse(flag)

    def test_level_size_invalid(self) -> None:
        """Test for invalid value, the default value is returned"""
        width, height, flag = validate_level_size({"width": 2, "height": 10})
        self.assertEqual(width, 15)
        self.assertEqual(height, 10)
        self.assertTrue(flag)

    def test_int_field_valid(self) -> None:
        """Test a valid integer field"""
        data = {"lives": 5}
        val = validate_int_field("lives", data, def_val=3, min_val=1)
        self.assertEqual(val, 5)

    def test_int_field_below_min(self) -> None:
        """Test an incorrect integer field, default value returned"""
        data = {"lives": 0}
        val = validate_int_field("lives", data, def_val=3, min_val=1)
        self.assertEqual(val, 3)

    def test_int_field_boolean(self) -> None:
        """Test an boolean field, default value returned"""
        data = {"lives": True}
        val = validate_int_field("lives", data, def_val=3, min_val=1)
        self.assertEqual(val, 3)

    def test_load_game_config_default_values(self) -> None:
        """Test all default value are applied if missing file"""
        config = load_game_config("non_existent_config.json")
        self.assertEqual(config["lives"], 3)
        self.assertEqual(config["highscore_filename"], "score.json")
        self.assertEqual(config["points_per_pacgum"], 20)
        self.assertEqual(config["points_per_super_pacgum"], 50)
        self.assertEqual(config["points_per_ghost"], 200)
        self.assertEqual(config["seed"], 42)
        self.assertEqual(config["level_max_time"], 360)
        self.assertEqual(config["number_level"], 10)
        for level in config["level_size"]:
            self.assertEqual(level, {"width": 15, "height": 15})
