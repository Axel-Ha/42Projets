NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SOURCES = ft_free_stack.c ft_nbrs_utils.c ft_get_args.c ft_list_utils.c ft_push_swap.c ft_split.c \
          ft_init_stack.c ft_utils.c ft_swap.c ft_rotate.c ft_rotate_reverse.c \
          ft_push.c ft_compute_disorder.c ft_select_sort.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re