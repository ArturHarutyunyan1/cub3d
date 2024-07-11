/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:21:15 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 02:26:00 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
void	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = (game->ceiling.r << 16) | (game->ceiling.g << 8)
		| game->ceiling.b;
	floor_color = (game->floor.r << 16) | (game->floor.g << 8) | game->floor.b;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			my_mlx_pixel_put(&game->img, x, y, ceiling_color);
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
			my_mlx_pixel_put(&game->img, x, y, floor_color);
		y++;
	}
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
