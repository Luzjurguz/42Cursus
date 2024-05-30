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

NAME = so_long
CFLAGS	= -Wextra -Wall -Werror
MLX42	= ./MLX42/libmlx42.a
LIBS	:= -ldl -lglfw3 -pthread -lm $(LIBMLX)
SRCS	:= cholo.c get_next_line/get_next_line.c
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(MLX42)
	@gcc $(OBJS) $(CFLAGS) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(MLX42):
	make -C MLX42

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	make -C MLX42 clean

fclean: clean
	@rm -f $(NAME)
	make -C MLX42 fclean

re: clean all

.PHONY: all, clean, fclean, re