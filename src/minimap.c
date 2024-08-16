/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:39:07 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/12 07:57:17 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	draw_cell(t_game *game, int map_x, int map_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			my_mlx_pixel_put(&game->img, (game->player.x - 0.5) * 10 + x,
				(game->player.y - 0.5) * 10 + y, 0xFF0000);
			my_mlx_pixel_put(&game->img, map_x * 10 + x, map_y * 10 + y, color);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	int	map_x;
	int	map_y;
	int	color;

	map_y = 0;
	while (map_y < game->map.height)
	{
		map_x = 0;
		while (map_x < game->map.width)
		{
			if (map_y < game->map.height
				&& map_x < (int)ft_strlen(game->map.dup[map_y]))
			{
				if (game->map.dup[map_y][map_x] == '1')
					color = 0x4169E1;
				else if (game->map.dup[map_y][map_x] == '0')
					color = 0x000000;
				else if (game->map.dup[map_y][map_x] == 'D')
					color = 0xa34a24;
				else if (game->map.grid[map_y][map_x] == 'd')
					color = 0x00FF00;
				else
					color = 0xFFFFFF;
				draw_cell(game, map_x, map_y, color);
			}
			map_x++;
		}
		map_y++;
	}
}
