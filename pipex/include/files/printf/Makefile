# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 21:15:14 by luz-mjur          #+#    #+#              #
#    Updated: 2023/07/12 17:35:47 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILE = ft_printf.c ft_print_char.c ft_print_decimal_int.c \
 ft_print_str.c ft_print_hex.c ft_print_punt.c\

OBJ = $(FILE:.c=.o)

FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#$(OBJ):
#	gcc $(FLAG) -c $(FILE)
%.o: %.c 
	gcc $(FLAG) -c -o $@ $<
	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re 