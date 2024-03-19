# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 01:01:09 by luz-mjur          #+#    #+#              #
#    Updated: 2023/06/15 16:12:07 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_memmove.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c	ft_memcmp.c ft_strnstr.c ft_atoi.c  ft_calloc.c ft_strdup.c \
ft_substr.c ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \


BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJ = $(FILE:.c=.o)

BONUSOBJ =$(BONUS:.c=.o)


FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): 
	gcc $(FLAG) -c $(FILE)

bonus: 
		gcc $(FLAG) -c $(BONUS)
		ar rcs $(NAME) $(BONUSOBJ)

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus