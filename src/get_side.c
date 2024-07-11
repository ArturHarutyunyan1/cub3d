/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_side.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:54:37 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 01:54:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

void	get_sides(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
		game->rays.vertical = NORTH;
	else
		game->rays.vertical = SOUTH;
	if (game->rays.ray_dir_y < 0)
		game->rays.horizontal = WEST;
	else
		game->rays.horizontal = EAST;
	set_step_and_side_dist_x(game);
	set_step_and_side_dist_y(game);
}

void	set_step_and_side_dist_x(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player.x - game->rays.map_x)
			* game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0 - game->player.x)
			* game->rays.delta_dist_x;
	}
}

void	set_step_and_side_dist_y(t_game *game)
{
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player.y - game->rays.map_y)
			* game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.y)
			* game->rays.delta_dist_y;
	}
}
