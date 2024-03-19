# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 14:42:29 by luz-mjur          #+#    #+#              #
#    Updated: 2024/03/13 00:51:16 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

FILE = push_swap.c  a.c b.c ab.c  utils.c costes.c mov.c errores.c utils2.c \
#BONUS = \

OBJ = $(FILE:.c=.o)

#BONUSOBJ = $(BONUS:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(LIBFT) $(OBJ) -o $(NAME)

#bonus: $(BONUSOBJ) $(LIBFT)
#gcc $(FLAG) $(BONUSOBJ) $(LIBFT) -o $(NAME)
	
%.o : %.c
	gcc $(FLAG) -c $< -o $@

$(LIBFT):
	make -C libft
	
#bonus/%.o : bonus/%.c
#gcc $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJ) 
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	
re: fclean all

.PHONY: clean fclean re 

