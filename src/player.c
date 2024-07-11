/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:03 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 01:13:30 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

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
