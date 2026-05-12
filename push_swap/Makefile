NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_get_args.c ft_list_utils.c ft_printf_utils.c ft_printf.c ft_push_swap.c  ft_split.c ft_init_stack.c ft_utils.c ft_swap.c ft_rotate.c ft_rotate_reverse.c ft_push.c ft_compute_disorder.c ft_bubble_sort.c ft_printf.c ft_printf_utils.c ft_list_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re