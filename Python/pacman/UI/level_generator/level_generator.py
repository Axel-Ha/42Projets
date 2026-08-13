import sys
from typing import Optional, Any

import pygame

from Characters.player_and_monsters import Ghosts, Player
from UI.Maze.Maze import Maze

from ..game_over_visual import game_over
from parsing import load_game_config


def infos_screen_left(window: pygame.Surface,
                      font_info: pygame.font.Font,
                      player: Player,
                      color: tuple[int, int, int],
                      size: tuple[int, int],
                      msg: str,
                      ) -> None:
    text_surface = font_info.render(msg, True, color)
    text_rect = text_surface.get_rect(
        bottomleft=size
    )
    window.blit(text_surface, text_rect)


def infos_screen_right(window: pygame.Surface,
                       font_info: pygame.font.Font,
                       player: Player,
                       color: tuple[int, int, int],
                       size: tuple[int, int],
                       msg: str,
                       ) -> None:
    text_surface = font_info.render(msg, True, color)
    text_rect = text_surface.get_rect(
        bottomright=size
    )
    window.blit(text_surface, text_rect)


def draw_maze(window: pygame.Surface,
              maze: "Maze",
              CELL_SIZE: int,
              player: Optional["Player"],
              level: int,
              font_info: pygame.font.Font,
              time: int,
              game_progression: dict[str, Any],
              ghosts_tuple: Optional[tuple["Ghosts", ...]] = None,
              ) -> None:
    WHITE = (255, 255, 255)
    WALL_COLOR = (33, 33, 255)
    PLAYER_COLOR = (255, 255, 0)
    DOT_COLOR = (240, 240, 240)
    SUPER_DOT_COLOR = (255, 165, 0)
    WALL_THICKNESS = 2
    SCREEN_WIDTH = maze.width * CELL_SIZE
    SCREEN_HEIGHT = maze.height * CELL_SIZE

    window_width = window.get_width()
    window_height = window.get_height()
    offset_x = (window_width - SCREEN_WIDTH) // 2
    offset_y = (window_height - SCREEN_HEIGHT) // 2 - 40

    for row_idx in range(maze.height):
        for col_idx in range(maze.width):
            x = col_idx * CELL_SIZE + offset_x
            y = row_idx * CELL_SIZE + offset_y
            cell_value = maze.maze[row_idx][col_idx]

            left = x
            right = min(x + CELL_SIZE - 1, offset_x + SCREEN_WIDTH - 1)
            top = y
            bottom = min(y + CELL_SIZE - 1, offset_y + SCREEN_HEIGHT - 1)

            top_left = (left, top)
            top_right = (right, top)
            bottom_left = (left, bottom)
            bottom_right = (right, bottom)

            if cell_value == 15:
                pygame.draw.rect(window,
                                 WHITE,
                                 (x, y, CELL_SIZE, CELL_SIZE)
                                 )
            # Bit 0 (1) -> Mur en HAUT
            if cell_value & 1:
                pygame.draw.line(window,
                                 WALL_COLOR,
                                 top_left,
                                 top_right,
                                 WALL_THICKNESS)

            # Bit 1 (2) -> Mur à DROITE
            if cell_value & 2:
                pygame.draw.line(window,
                                 WALL_COLOR,
                                 top_right,
                                 bottom_right,
                                 WALL_THICKNESS)

            # Bit 2 (4) -> Mur en BAS
            if cell_value & 4:
                pygame.draw.line(window,
                                 WALL_COLOR,
                                 bottom_left,
                                 bottom_right,
                                 WALL_THICKNESS)

            # Bit 3 (8) -> Mur à GAUCHE
            if cell_value & 8:
                pygame.draw.line(window,
                                 WALL_COLOR,
                                 top_left,
                                 bottom_left,
                                 WALL_THICKNESS)

            if maze.cases[(col_idx, row_idx)].has_pacgum and cell_value != 15:
                center_x = x + CELL_SIZE // 2
                center_y = y + CELL_SIZE // 2
                dot_radius = CELL_SIZE // 6
                pygame.draw.circle(window,
                                   DOT_COLOR,
                                   (center_x, center_y),
                                   dot_radius)

            if (maze.cases[(col_idx, row_idx)].has_super_pacgum
                    and cell_value != 15):
                center_x = x + CELL_SIZE // 2
                center_y = y + CELL_SIZE // 2
                dot_radius = CELL_SIZE // 6
                pygame.draw.circle(window,
                                   SUPER_DOT_COLOR,
                                   (center_x, center_y),
                                   dot_radius)

    if player:
        infos_screen_left(window,
                          font_info,
                          player,
                          WHITE,
                          (15,
                           offset_y + SCREEN_HEIGHT + (1 * CELL_SIZE) + 10),
                          f"Lives: {game_progression["player_lives"]}")

        infos_screen_left(window,
                          font_info,
                          player,
                          WHITE,
                          (15, offset_y + SCREEN_HEIGHT + (3 * CELL_SIZE)),
                          f"Score: {game_progression["player_score"]}")

        infos_screen_right(window,
                           font_info,
                           player,
                           WHITE,
                           (window_width,
                            offset_y + SCREEN_HEIGHT + (1 * CELL_SIZE) + 10),
                           f"Current level: {level}",
                           )

        infos_screen_right(window,
                           font_info,
                           player,
                           WHITE,
                           (window_width,
                            offset_y + SCREEN_HEIGHT + (3 * CELL_SIZE)),
                           f"Time left: {time // 1000} s",
                           )

        if player.coords and not player.is_dead:
            if maze.cases[player.coords].content == 15:
                player_new_x: int = player.coords[0] + 1
            else:
                player_new_x = player.coords[0]
            player.coords = (player_new_x, player.coords[1])
            player_x = player_new_x * CELL_SIZE + CELL_SIZE // 2 + offset_x
            player_y = player.coords[1] * CELL_SIZE + CELL_SIZE // 2 + offset_y
            # -5 to avoid drawing on walls
            radius = max(5, ((CELL_SIZE // 2) - 2) - 5)

            pygame.draw.circle(window,
                               PLAYER_COLOR,
                               (player_x, player_y),
                               radius)

    if ghosts_tuple:
        for ghost in ghosts_tuple:
            if not ghost.is_dead:
                x = ghost.coords[0] * CELL_SIZE + CELL_SIZE // 2 + offset_x
                y = ghost.coords[1] * CELL_SIZE + CELL_SIZE // 2 + offset_y
                radius = (CELL_SIZE // 2 - 2) - 5

                pygame.draw.circle(window,
                                   ghost.color_to_draw,
                                   (x, y),
                                   radius)


def check_pacgum(maze: "Maze") -> bool:
    for case in maze.cases.values():
        if case.has_pacgum or case.has_super_pacgum:
            return False
    return True


def new_level(game_progression: dict[str, Any],
              window: pygame.Surface,
              infos: tuple[int, int, int, int, int, int],
              highscore_filename: str,
              cheat_settings: dict[str, Any],
              seed: int | None = None,
              ) -> str | None:
    if game_progression['first_game']:
        level_nb: int = 0
        level = game_progression["remaining_level"][level_nb]
        width = level['width']
        height = level['height']

        return level_generator(width, height, 0, infos,
                               game_progression, window,
                               highscore_filename, cheat_settings, seed)
    else:
        level_nb = game_progression['current_level']
        level = game_progression["remaining_level"][level_nb]
        width = level['width']
        height = level['height']
        infos = (game_progression["player_lives"],) + infos[1:]
        return level_generator(width, height, level_nb,
                               infos, game_progression,
                               window, highscore_filename, cheat_settings)


def pause(window: pygame.Surface, clock: pygame.time.Clock) -> int:
    """
    Pause the game and return time passed while paused
    """
    pause_start = pygame.time.get_ticks()
    overlay = pygame.Surface((window.get_width(),
                              window.get_height()),
                             pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 150))
    window.blit(overlay, (0, 0))

    font = pygame.font.SysFont("arial", 80, bold=True)
    text_surf = font.render("PAUSE", True, (255, 255, 255))
    text_rect = text_surf.get_rect(center=(window.get_width() // 2,
                                           window.get_height() // 2 - 50))
    window.blit(text_surf, text_rect)

    font_small = pygame.font.SysFont("arial", 30)
    sub_surf = font_small.render("Press Esc to continue",
                                 True, (200, 200, 200))
    sub_rect = sub_surf.get_rect(center=(window.get_width() // 2,
                                         window.get_height() // 2 + 50))
    sub_surf_quit = font_small.render("Press q to quit",
                                      True, (200, 200, 200))
    sub_rect_quit = sub_surf.get_rect(center=(window.get_width() // 2 + 50,
                                      window.get_height() // 2 + 100))
    window.blit(sub_surf, sub_rect)
    window.blit(sub_surf_quit, sub_rect_quit)

    pygame.display.flip()

    is_paused = True
    while is_paused:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                keys = pygame.key.get_pressed()
                if keys[pygame.K_q]:
                    from UI.main_menu.menu import menu
                    menu(load_game_config("config.json"))
                if event.key == pygame.K_ESCAPE:
                    is_paused = False

        clock.tick(15)

    return pygame.time.get_ticks() - pause_start


def level_generator(width: int,
                    height: int,
                    level_number: int,
                    infos: tuple[int, int, int, int, int, int],
                    game_progression: dict[str, Any],
                    window: pygame.Surface,
                    highscore_filename: str,
                    cheat_settings: dict[str, Any],
                    seed: int | None = None
                    ) -> str | None:
    player = Player(((width // 2) - 1, height // 2), level_number,
                    game_progression["player_lives"])
    red = Ghosts((0, 0), (255, 0, 0), level_number)
    green = Ghosts((0, height - 1), (0, 128, 0), level_number)
    blue = Ghosts((width - 1, 0), (0, 0, 255), level_number)
    pink = Ghosts((width - 1, height - 1), (255, 192, 203), level_number)
    ghosts_tuple: tuple[Ghosts, Ghosts, Ghosts, Ghosts] = (
        red,
        green,
        blue,
        pink
    )
    maze = Maze(width, height, seed)
    CELL_SIZE = 30
    BLACK = (0, 0, 0)

    pygame.init()
    pygame.display.set_caption(f"PAC-MAN - LEVEL {level_number + 1}")
    pygame.font.init()
    font = pygame.font.SysFont("arial", 48)
    font_info = pygame.font.SysFont("arial", 30)

    clock = pygame.time.Clock()
    level_start_time = pygame.time.get_ticks()
    total_pause_time: int = 0

    running: bool = True
    status = "quit"
    while running:
        current_time = pygame.time.get_ticks() - total_pause_time
        elapsed_time = current_time - level_start_time
        if cheat_settings["invincible"]:
            player.super = True
            player.super_time = current_time
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    total_pause_time += pause(window, clock)
        if player:
            if not player.is_dead:
                keys = pygame.key.get_pressed()
                if (current_time - player.last_moves >= player.move_delay):
                    content: int = maze.cases[player.coords].content
                    if keys[pygame.K_UP] and not (content & 1):
                        player.move_up(maze)
                        player.last_moves = current_time
                    elif keys[pygame.K_DOWN] and not (content & 4):
                        player.move_down(maze)
                        player.last_moves = current_time
                    elif keys[pygame.K_RIGHT] and not (content & 2):
                        player.move_right(maze)
                        player.last_moves = current_time
                    elif keys[pygame.K_LEFT] and not (content & 8):
                        player.move_left(maze)
                        player.last_moves = current_time
            if player.is_dead:
                if current_time - player.death_time >= player.respawn_delay:
                    player.is_dead = False
                    player.coords = player.coords_spawn

            if player.coords != (-1, -1) and not player.is_dead:
                if player.super:
                    if current_time - player.super_time >= 3000:
                        player.super = False
                if maze.cases[(player.coords)].has_pacgum:
                    player.eat(infos[1])
                    game_progression["player_score"] += infos[1]
                    maze.cases[(player.coords)].has_pacgum = False

                elif maze.cases[(player.coords)].has_super_pacgum:
                    player.eat(infos[2])
                    game_progression["player_score"] += infos[2]
                    maze.cases[(player.coords)].has_super_pacgum = False
                    player.super = True
                    player.super_time = current_time

            if ghosts_tuple:
                for ghost in ghosts_tuple:
                    if ghost.is_dead:
                        if (current_time - ghost.death_time
                                >= ghost.respawn_delay):
                            ghost.is_dead = False
                            ghost.coords = ghost.coords_spawn
                        else:
                            continue

                    if not ghost.is_dead:
                        if player.super:
                            if (current_time - ghost.last_blink
                                    >= ghost.blink_delay):
                                ghost.blink()
                                ghost.last_blink = current_time
                        elif ghost.color_to_draw == BLACK:
                            ghost.blink()
                        if (current_time - ghost.last_moves_time
                                >= ghost.move_delay
                                and not cheat_settings["ghost_freeze"]):
                            ghost.movements(maze, player, level_number)
                            ghost.last_moves_time = current_time
                        if ghost.coords == player.coords:
                            if not player.super:
                                ghost.eat(player)
                                player.is_dead = True
                                game_progression["player_lives"] -= 1
                                player.death_time = pygame.time.get_ticks()
                                player.coords = (-1, -2)
                            else:
                                player.eat(3)
                                game_progression["player_score"] += infos[3]
                                ghost.is_dead = True
                                ghost.death_time = pygame.time.get_ticks()
                                ghost.coords = (-1, -1)

        time_limit = infos[4] * 1000
        window.fill(BLACK)
        if maze:
            if check_pacgum(maze) and level_number + 1 == infos[5]:
                status = game_over(window, font, True, highscore_filename,
                                   game_progression["player_score"])
                running = not running
            elif check_pacgum(maze):
                game_progression["first_game"] = False
                game_progression["current_level"] += 1
                return new_level(game_progression, window, infos,
                                 highscore_filename, cheat_settings)
            elif (player and player.nb_lives <= 0) or (time_limit -
                                                       elapsed_time <= 0):
                status = game_over(window, font, False, highscore_filename,
                                   game_progression["player_score"])
                running = not running
            else:
                draw_maze(window,
                          maze,
                          CELL_SIZE,
                          player,
                          level_number + 1,
                          font_info,
                          time_limit - elapsed_time,
                          game_progression,
                          ghosts_tuple)
        pygame.display.flip()
        clock.tick(60)

    if status == "quit":
        sys.exit()
    elif status == "new game":
        game_progression = {
            "first_game": True,
            "current_level": 0,
            "player_lives": infos[0],
            "player_score": -20,
        }
        return level_generator(width,
                               height,
                               level_number,
                               infos,
                               game_progression,
                               window,
                               highscore_filename,
                               cheat_settings,
                               seed)
    return status
