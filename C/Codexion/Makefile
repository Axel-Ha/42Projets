NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = Parsing/ft_check_atoi.c Parsing/parsing.c \
		  init_struct.c main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

run:
	./$(NAME) 2 100 30 40 50 3 20 fifo


clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re