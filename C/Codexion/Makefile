NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = Parsing/ft_check_atoi.c Parsing/parsing.c \
		  memory/ft_init_struct.c memory/ft_free.c \
		  time/management_time.c \
		  log/ft_log.c \
		  coder/ft_coder.c \
		  dongle/ft_dongle.c \
		  thread/ft_thread.c \
		  monitor/ft_monitor.c \
		  main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

run:
	./$(NAME) 2 800 200 200 200 3 200 fifo

valgrind:
	valgrind --leak-check=yes ./$(NAME) 5 100 30 40 50 3 20 fifo

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re valgrind