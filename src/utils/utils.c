/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:51 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/10 06:39:52 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void clear_image(t_game *game)
{
    int x, y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, 0x000000);  // Clear to black (0x000000)
            x++;
        }
        y++;
    }
}

int	ft_exit(t_game *game, char *msg, int status)
{
	printf("%s", msg);
	if (status == 2)
	{
		mlx_destroy_image(game->vars.mlx, game->textures[0].img);
		mlx_destroy_image(game->vars.mlx, game->textures[1].img);
		mlx_destroy_image(game->vars.mlx, game->textures[2].img);
		mlx_destroy_image(game->vars.mlx, game->textures[3].img);
		mlx_destroy_image(game->vars.mlx, game->img.img);
		mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	}
	free_matrix(game->map.grid);
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