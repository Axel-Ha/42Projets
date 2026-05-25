NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SOURCES = 	medium/ft_chunk_sort.c medium/ft_sqrt.c \
			utils/ft_list_utils.c utils/ft_utils.c utils/ft_nbrs_utils.c \
		  	operations/ft_swap.c operations/ft_rotate_reverse.c operations/ft_rotate.c operations/ft_push.c \
		  	ft_free_stack.c ft_get_args.c  ft_push_swap.c  \
          	ft_init.c ft_compute_disorder.c ft_select_sort.c \
			complexe/ft_radix_sort.c main.c

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