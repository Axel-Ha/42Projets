NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strlen.c ft_toupper.c \
		  	ft_tolower.c ft_isascii.c ft_strlcpy.c ft_bzero.c ft_memcpy.c \
			ft_memset.c
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