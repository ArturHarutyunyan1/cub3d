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


void init_game();
int	exit_game(t_vars *vars);

#endif