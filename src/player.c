/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:03 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/03 02:32:36 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

bool	is_looking_at_door(t_game *game)
{
	int next_x;
	int next_y;

	next_x = (int)(game->player.x + game->player.dir_x);
	next_y = (int)(game->player.y + game->player.dir_y);
	if ((abs(next_x - (int)game->player.x) <= 1 && abs(next_y - (int)game->player.y) <= 1)
		&& (game->map.grid[next_y][next_x] == 'D' || game->map.grid[next_y][next_x] == 'd'))
		return (true);

	return (false);
}


void	door(t_game *game)
{
	int next_x;
	int next_y;

	next_x = (int)(game->player.x + game->player.dir_x);
	next_y = (int)(game->player.y + game->player.dir_y);
	
	if (game->map.grid[next_y][next_x] == 'D')
		game->map.grid[next_y][next_x] = 'd';
	else if (game->map.grid[next_y][next_x] == 'd')
		game->map.grid[next_y][next_x] = 'D';
}

void	update_player(t_game *game)
{
	if (game->key_states[KEY_W])
		move_forward(game);
	if (game->key_states[KEY_S])
		move_backwards(game);
	if (game->key_states[KEY_A])
		move_left(game);
	if (game->key_states[KEY_D])
		move_right(game);
	if (game->key_states[LEFT_ARROW])
		rotate_left(game);
	if (game->key_states[RIGHT_ARROW])
		rotate_right(game);
}