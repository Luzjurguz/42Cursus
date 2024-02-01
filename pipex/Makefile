# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:17:06 by luz-mjur          #+#    #+#              #
#    Updated: 2024/01/11 13:13:07 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


FILE = pipex.c 
BONUS = bonus/pipex_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT = libft/libft.a
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
	make -C libft
	
bonus/%.o : bonus/%.c
	gcc $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJ) 
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	
re: fclean all

.PHONY: clean fclean re 

