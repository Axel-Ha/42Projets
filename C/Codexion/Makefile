NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = Parsing/ft_check_atoi.c Parsing/parsing.c \
		  memory/ft_init_struct.c memory/ft_free.c \
		  time/management_time.c \
		  log/ft_log.c \
		  coder/ft_coder.c \
		  dongle/ft_dongle.c dongle/ft_dongle_2.c \
		  thread/ft_thread.c \
		  monitor/ft_monitor.c \
		  heap/ft_heap.c \
		  main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

run:
	./$(NAME) 5 800 200 200 200 3 0 fifo
	./$(NAME) 5 310 200 100 100 5 0 fifo

valgrind:
	valgrind --leak-check=yes ./$(NAME) 5 100 30 40 50 3 20 fifo

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re valgrind
