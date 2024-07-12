# Name of the executable
NAME = cub3D

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = mlx

# Source files
SRC_FILES = get_side.c init_game.c input_handling.c main.c map_utils.c \
            map_utils1.c movement.c parsing.c parsing_utils.c player.c \
            player_init.c raycaster.c raycaster_setup.c read_map.c render.c \
            rotate.c setup.c utils.c utils1.c validation.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Includes
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

# Compilation and linking
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lm -lmlx -lXext -lX11 -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	ranlib $(LIBFT)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
