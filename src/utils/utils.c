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

int	ft_exit(t_game *game, char *msg, int status)
{
	printf("%s", msg);
	(void)game;
	// free_matrix(game->map.grid);
	// mlx_destroy_image(game->vars.mlx, game->img.img);
	// mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	exit(status);
}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int exit_game(t_game *game)
{
	ft_exit(game, "Game was closed successfully\n", 0);
	return (0);
}