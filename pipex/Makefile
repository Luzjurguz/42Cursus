# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:17:06 by luz-mjur          #+#    #+#              #
#    Updated: 2024/02/09 23:54:34 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = bonus/pipex_bonus.c
FILE = pipex.c 
LIBFT = include/libft.a
OBJ = $(FILE:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)
FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(LIBFT) $(OBJ) -o $(NAME)

bonus: $(BONUSOBJ) $(LIBFT)
	gcc $(FLAG) $(BONUSOBJ) $(LIBFT) -o $(NAME)
	
%.o : %.c
	gcc $(FLAG) -c $< -o $@

$(LIBFT):
	make -C include
	
bonus/%.o : bonus/%.c
	gcc $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJ) 
	make -C include clean

fclean: clean
	rm -f $(NAME)
	make -C include fclean
	
re: fclean all

.PHONY: clean fclean re 

