# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 22:17:06 by luz-mjur          #+#    #+#              #
#    Updated: 2024/10/08 22:45:28 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS	= -Wextra -Wall -Werror
MLX42	= ./MLX42/libmlx42.a
LIBFT   = ./libft/libft.a
LIBS	:= -ldl -g -lglfw3 -lm $(LIBMLX)
SRCS	:= src/cholo.c src/movimiento.c src/parseo_char.c src/parseo_map.c \
src/textu.c src/utils.c src/lics.c
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(MLX42) $(LIBFT)
	@gcc $(OBJS) $(CFLAGS) $(MLX42) $(LIBFT) -fPIE -Iinclude -ldl -lglfw -lm -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX42):
	make -C MLX42

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	make -C MLX42 clean
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	make -C MLX42 fclean
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re