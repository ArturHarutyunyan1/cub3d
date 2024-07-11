# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 06:40:11 by arturhar          #+#    #+#              #
#    Updated: 2024/07/10 06:40:12 by arturhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -arch x86_64 # -g3 -fsanitize=address
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

SRCS = $(wildcard src/*.c) \
       $(wildcard src/utils/*.c)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) Makefile ./include
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
