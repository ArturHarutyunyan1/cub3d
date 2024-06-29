#include "../../include/cub.h"

int	exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("Game was closed successfully!\n");
	exit(0);
}