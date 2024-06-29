#include "../include/cub.h"

void init_game()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Cub3D");
    mlx_hook(vars.mlx_win, 17, 0, exit_game, &vars);
    mlx_loop(vars.mlx);
}