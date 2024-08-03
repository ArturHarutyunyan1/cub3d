/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:51 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/03 09:43:14 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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
	int	i;

	printf("%s", msg);
	i = 0;
	if (game != NULL)
	{
		if (status == 2)
		{
			while (game->textures[i].img || game->sprite[i].img)
			{
				if (game->textures[i].img)
					mlx_destroy_image(game->vars.mlx, game->textures[i].img);
				if (game->sprite[i].img)
					mlx_destroy_image(game->vars.mlx, game->sprite[i].img);
				i++;
			}
			if (game->vars.mlx_win)
				mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
		}
	}
	free_matrix(game->map.grid);
	ft_lstclear(&game->file, free);
	exit(status);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_game(t_game *game)
{
	ft_exit(game, "Game was closed successfully\n", 0);
	return (0);
}

void	cleanup(t_game *game)
{
	free_matrix(game->map.grid);
	free(game->map.no);
	free(game->map.so);
	free(game->map.we);
	free(game->map.ea);
	free(game->map.f);
	free(game->map.c);
}
