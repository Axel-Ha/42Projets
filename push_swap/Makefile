NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SOURCES = 	medium/ft_chunk_sort.c medium/ft_sqrt.c \
          	utils/ft_free_stack.c utils/ft_get_args.c  utils/ft_init.c utils/ft_compute_disorder.c utils/ft_list_utils.c utils/ft_utils.c utils/ft_nbrs_utils.c \
		  	operations/ft_swap.c operations/ft_rotate_reverse.c operations/ft_rotate.c operations/ft_push.c \
			srcs/ft_push_swap.c main.c \
			complexe/ft_radix_sort.c  simple/ft_select_sort.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re