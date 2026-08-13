import pygame

from score import set_highscore

from .main_menu.ui_helpers import clicked, make_text


def game_over(
    window: pygame.Surface,
    font: pygame.font.Font,
    is_win: bool,
    highscore_file: str,
    score: int,
) -> str:
    if not is_win:
        pygame.display.set_caption("GAME OVER")
    else:
        pygame.display.set_caption("CONGRATULATION")

    BLACK = (0, 0, 0)

    window.fill(BLACK)
    center_x = window.get_width() // 2
    box_width = 280
    box_height = 50
    box_x = center_x - (box_width // 2)

    clock = pygame.time.Clock()
    default_color = pygame.Color("dodgerblue2")
    color_limit_reached = pygame.Color("red")
    color = default_color
    text = "Joe"
    running = True
    action = "main menu"
    is_saved = False

    if not is_win:
        text_status, rect_status = make_text(
            font, "GAME OVER", center=(center_x,
                                       window.get_height() // 6)
        )
    else:
        text_status, rect_status = make_text(
            font, "CONGRATULATION", center=(center_x,
                                            window.get_height() // 6)
        )
    text_score, rect_score = make_text(
        font, f"Your score {score}", center=(center_x,
                                             rect_status.bottom + 100)
    )
    text_nickname, rect_nickname = make_text(
        font, "Enter Nickname", center=(center_x, rect_score.bottom + 80)
    )

    text_main_menu, rect_main_menu = make_text(
        font, "Main menu", center=(center_x - 200, rect_nickname.bottom + 100)
    )
    text_new_game, rect_new_game = make_text(
        font, "New game", center=(center_x + 200, rect_main_menu.centery)
    )
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return "quit"
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    return "quit"
                elif event.key == pygame.K_RETURN:
                    if len(text.strip()) != 0:
                        set_highscore(highscore_file, (text, score))
                        is_saved = True
                elif event.key == pygame.K_BACKSPACE:
                    text = text[:-1]
                    color = default_color
                else:
                    if len(text) != 10:
                        if event.unicode.isalnum() or event.unicode.isspace():
                            text += event.unicode
                            color = default_color
                    else:
                        color = color_limit_reached
            elif clicked(event, rect_main_menu):
                return "main menu"
            elif clicked(event, rect_new_game):
                return "new game"

        window.fill(BLACK)
        window.blit(text_status, rect_status)
        window.blit(text_score, rect_score)
        window.blit(text_nickname, rect_nickname)
        window.blit(text_main_menu, rect_main_menu)
        window.blit(text_new_game, rect_new_game)

        if is_saved:
            tmp_font = pygame.font.SysFont("arial", 20)
            text_saved, rect_saved = make_text(
                tmp_font, "Score saved", center=(rect_nickname.right + 50,
                                                 rect_nickname.bottom + 35)
            )
            window.blit(text_saved, rect_saved)

        # Draw input box
        box_y = rect_nickname.bottom + 15
        input_box = pygame.Rect(box_x, box_y, box_width, box_height)
        pygame.draw.rect(window, color, input_box, 2)

        # Draw the input letters
        txt_surface = font.render(text, True, (255, 255, 255))
        window.blit(txt_surface, (input_box.x + 10, input_box.y + 5))

        text_instruction, rect_instruction = make_text(
            font, "Press enter to save", center=(center_x,
                                                 input_box.bottom + 100)
        )

        window.blit(text_instruction, rect_instruction)
        pygame.display.flip()
        clock.tick(30)

    return action
