import unittest
from Characters.player_and_monsters import Player, Ghosts


class TestTimeLogic(unittest.TestCase):
    """
    Time logic tests.
    """

    def setUp(self) -> None:
        """
        Context initialisation.
        """
        self.player = Player(coords_spawn=(1, 1), level=0)
        self.ghost = Ghosts(coords_spawn=(10, 10), color=(255, 0, 0), level=0)

    def test_super_pacgum_duration(self) -> None:
        """
        Check if the player "super" statut are gone after 3000ms
        """
        self.player.super = True
        self.player.super_time = 1000

        current_time = 2500
        if current_time - self.player.super_time >= 3000:
            self.player.super = False
        self.assertTrue(self.player.super)

        current_time = 4500
        if current_time - self.player.super_time >= 3000:
            self.player.super = False
        self.assertFalse(self.player.super)

    def test_ghost_respawn_after_2_seconds(self) -> None:
        """
        Dead ghosts respawn at respawn point after 2000ms.
        """
        self.ghost.is_dead = True
        self.ghost.death_time = 5000
        self.ghost.coords = (-1, -1)

        current_time = 6000
        if self.ghost.is_dead:
            if current_time - self.ghost.death_time >= 2000:
                self.ghost.is_dead = False
                self.ghost.coords = self.ghost.coords_spawn

        self.assertTrue(self.ghost.is_dead)

        current_time = 7500
        if self.ghost.is_dead:
            if current_time - self.ghost.death_time >= 2000:
                self.ghost.is_dead = False
                self.ghost.coords = self.ghost.coords_spawn

        self.assertFalse(self.ghost.is_dead)
        self.assertEqual(self.ghost.coords, self.ghost.coords_spawn)
