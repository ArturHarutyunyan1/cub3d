#ifndef CUB
#define CUB

#include "../libft/include/libft.h"
#include "../mlx/mlx.h"
#include <stdbool.h>
#include <math.h>

// Default window size

#define WIDTH 1024
#define HEIGHT 768

// Keycodes

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define LEFT_ARROW 123
#define RIGHT_ARROW 124

typedef struct s_vars
{
    void *mlx;
    void *mlx_win;
}t_vars;

typedef struct s_map
{
    int widht;
    int height;
    char **grid;
}t_map;

typedef struct s_img
{
    void *img;
    char *data;
    int *size;
    int bpp;
}t_img;

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
}t_player;

typedef struct s_game
{
    t_vars vars;
    t_map map;
    t_player player;
}t_game;

void init_game(char *argv);
char **read_map(char *path);
t_map init_map(char **str);
int	exit_game(t_vars *vars);

#endif