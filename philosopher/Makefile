# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 19:01:50 by luz-mjur          #+#    #+#              #
#    Updated: 2024/11/19 19:03:48 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

FILE = philosopher.c
#BONUS = \

OBJ = $(FILE:.c=.o)

#BONUSOBJ = $(BONUS:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(OBJ) -o $(NAME)

#bonus: $(BONUSOBJ)
#gcc $(FLAG) $(BONUSOBJ) -o $(NAME)
	
%.o : %.c
	gcc $(FLAG) -c $< -o $@
	
#bonus/%.o : bonus/%.c
#gcc $(FLAG) -c $< -o $@


clean:
	rm -f $(OBJ) 
	make -C clean

fclean: clean
	rm -f $(NAME)
	make -C fclean
	
re: fclean all

.PHONY: clean fclean re 
