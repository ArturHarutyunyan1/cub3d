#include "../../include/cub.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	exit_game(t_game *game)
{
	// free_matrix(game->map.grid);
	mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	printf("Game was closed successfully!\n");
	exit(0);
}