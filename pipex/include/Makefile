# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 23:41:44 by luz-mjur          #+#    #+#              #
#    Updated: 2024/02/09 23:49:42 by luz-mjur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_NAMES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp\
ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup\
ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi\
ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus\
ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus\
ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

PRINTF_NAMES = ft_print_char ft_print_decimal_int ft_print_hex ft_print_punt \
ft_print_str ft_printf

GNL_NAMES = get_next_line get_next_line_utils

FLAGS = -Wall -Wextra -Werror

LIBFT_SRC = files/libft/
LIBFT_OBJS = objs/libft/

PRINTF_SRC = files/printf/
PRINTF_OBJS = objs/printf/

GNL_SRC = files/get_next_line/
GNL_OBJS = objs/get_next_line/

LIBFT_FILES = $(addprefix $(LIBFT_SRC), $(addsuffix .c, $(LIBFT_NAMES)))
LIBFT_OBJECT = $(addprefix $(LIBFT_OBJS), $(addsuffix .o, $(LIBFT_NAMES)))

PRINTF_FILES = $(addprefix $(PRINTF_SRC), $(addsuffix .c, $(PRINTF_NAMES)))
PRINTF_OBJECT = $(addprefix $(PRINTF_OBJS), $(addsuffix .o, $(PRINTF_NAMES)))

GNL_FILES = $(addprefix $(GNL_SRC), $(addsuffix .c, $(GNL_NAMES)))
GNL_OBJECT = $(addprefix $(GNL_OBJS), $(addsuffix .o, $(GNL_NAMES)))

all: $(NAME)

$(NAME): $(LIBFT_OBJECT) $(PRINTF_OBJECT) $(GNL_OBJECT)
	@ar rcs $(NAME) $(LIBFT_OBJECT) $(PRINTF_OBJECT) $(GNL_OBJECT)

$(LIBFT_OBJECT): $(LIBFT_FILES)
	@mkdir -p $(LIBFT_OBJS)
	@gcc $(FLAGS) -c $(LIBFT_FILES)
	@mv $(addsuffix .o, $(LIBFT_NAMES)) $(LIBFT_OBJS)

$(PRINTF_OBJECT): $(PRINTF_FILES)
	@mkdir -p $(PRINTF_OBJS)
	@gcc $(FLAGS) -c $(PRINTF_FILES)
	@mv $(addsuffix .o, $(PRINTF_NAMES)) $(PRINTF_OBJS)

$(GNL_OBJECT): $(GNL_FILES)
	@mkdir -p $(GNL_OBJS)
	@gcc $(FLAGS) -c $(GNL_FILES)
	@mv $(addsuffix .o, $(GNL_NAMES)) $(GNL_OBJS)


clean:
	@rm -rf objs/

fclean:
	@rm -rf $(NAME) objs/

re: fclean all

.PHONY: all clean fclean re