NAME = libft.a

FILE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
 ft_strlcpy.c ft_memmove.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\

OBJ = $(FILE:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): 
	$(CC) $(FLAG) -c $(FILE)


clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME) 

re: fclean all

.PHONY: clean fclean req