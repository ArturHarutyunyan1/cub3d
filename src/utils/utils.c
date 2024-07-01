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

int	exit_game(t_game *game, char *msg, int status)
{
	printf("%s", msg);
	printf("ERROR LINE %s", game->map.grid[0]);
	// free_matrix(game->map.grid);
	// mlx_destroy_image(game->vars.mlx, game->img.img);
	// mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	exit(status);
}