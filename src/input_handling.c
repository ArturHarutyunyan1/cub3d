/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:08:26 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/18 23:05:01 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
int	keypress(int code, t_game *game)
{
	if (code >= 0 && code < KEY_COUNT)
		game->key_states[code] = 1;
	if (code == KEY_ESC)
		exit_game(game);
	return (0);
}

int	keyrelease(int code, t_game *game)
{
	if (code >= 0 && code < KEY_COUNT)
		game->key_states[code] = 0;
	return (0);
}

int	game_loop(t_game *game)
{
	clear_image(game);
	draw_floor_and_ceiling(game);
	update_player(game);
	raycaster(game);
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.mlx_win,
		game->img.img, 0, 0);
	return (0);
}
