#ifndef CUB
#define CUB

#include "../libft/include/libft.h"
#include "../mlx/mlx.h"
#include <stdbool.h>
#include <math.h>

// Default window size

#define WIDTH 640
#define HEIGHT 480

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
    int width;
    int height;
    char **grid;
}t_map;

typedef struct s_img
{
    void *img;
    char *data;
    int size[2];
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

typedef struct s_rays
{
    double camera_x;
    double camera_y;
    double ray_dir_x;
    double ray_dir_y;
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double side_dist_y;
    double perp_wall_dist;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int hit;
    int side;
}t_rays;

typedef struct s_game
{
    t_vars vars;
    t_map map;
    t_img img;
    t_rays rays;
    t_player player;
}t_game;

void init_game(char *argv);
char **read_map(char *path);
t_map init_map(char **str);
void init_player(t_game *game);
int	exit_game(t_game *game);
void init_rays(t_game *game);
void	free_matrix(char **matrix);

#endif