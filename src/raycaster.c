/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:05 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 01:44:29 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub.h"
void	prepare_drawing(t_game *game)
{
	calculate_perp_wall_dist_and_direction(game);
    calculate_draw_limits_and_tex_x(game);
}

static void	draw_wall(t_game *game, int x)
{
	int			y;
	int			color;
	t_texture	*texture;

	texture = &game->textures[game->rays.direction];
	game->rays.step = 1.0 * texture->height / game->rays.line_height;
	game->rays.tex_pos = (game->rays.draw_start - HEIGHT
			/ 2 + game->rays.line_height / 2)
		* game->rays.step;
	y = game->rays.draw_start;
	while (y < game->rays.draw_end)
	{
		game->rays.tex_y = (int)game->rays.tex_pos & (texture->height - 1);
		game->rays.tex_pos += game->rays.step;
		color = *(int *)(texture->addr
				+ (game->rays.tex_y * texture->line_length
					+ game->rays.tex_x
					* (texture->bpp / 8)));
		if (game->rays.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

void	raycaster(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		setup(game, x);
		get_sides(game);
		dda(game);
		prepare_drawing(game);
		if (game->rays.hit == 1)
			draw_wall(game, x);
		x++;
	}
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.mlx_win,
		game->img.img, 0, 0);
}
