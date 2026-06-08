NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INCLUDE_PATH = -I includes

SOURCES = 	algorithms/ft_chunk_sort.c algorithms/ft_sqrt.c algorithms/ft_radix_sort.c  algorithms/ft_select_sort.c \
          	utils/ft_free_stack.c utils/ft_get_args.c  utils/ft_init.c utils/ft_compute_disorder.c utils/ft_list_utils.c utils/ft_nbrs_utils.c \
		  	operations/ft_swap.c operations/ft_rotate_reverse.c operations/ft_rotate.c operations/ft_push.c \
			srcs/ft_push_swap.c srcs/main.c \
			

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_PATH)
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re