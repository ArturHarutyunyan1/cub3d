/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:54:41 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/20 21:54:42 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_mouse(t_game *game)
{
	game->mouse.last_x = WIDTH / 2;
	mlx_mouse_move(game->vars.mlx_win, WIDTH / 2, HEIGHT / 2);
}

int	mouse_move(int x, int y, t_game *game)
{
	int	delta_x;

	(void)y;
	delta_x = x - game->mouse.last_x;
	if (delta_x > 0)
	{
		while (delta_x-- > 0)
			rotate_right(game);
	}
	else if (delta_x < 0)
	{
		while (delta_x++ < 0)
			rotate_left(game);
	}
	game->mouse.last_x = x;
	return (0);
}
