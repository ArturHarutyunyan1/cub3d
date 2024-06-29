NAME = Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

SRCS = $(wildcard src/*.c) \
       $(wildcard src/utils/*.c)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) Makefile include
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
