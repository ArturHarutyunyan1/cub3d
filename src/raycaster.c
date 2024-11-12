/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:05 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/03 01:26:35 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	prepare_drawing(t_game *game)
{
	calculate_perp_wall_dist_and_direction(game);
	calculate_draw_limits_and_tex_x(game);
}

static void	set_texture_and_step(t_game *game, t_texture **texture)
{
	if (game->rays.hit == 2)
		*texture = &game->textures[4];
	else if (game->rays.hit == 3)
		*texture = &game->textures[5];
	else
		*texture = &game->textures[game->rays.direction];
	game->rays.step = (double)(*texture)->height / game->rays.line_height;
}

static void	draw_wall_pixel(t_game *game, int x, int y, t_texture *texture)
{
	int	color;

	game->rays.tex_y = (int)game->rays.tex_pos & (texture->height - 1);
	game->rays.tex_pos += game->rays.step;
	color = *(int *)(texture->addr + (game->rays.tex_y * texture->line_length
				+ game->rays.tex_x * (texture->bpp / 8)));
	if (game->rays.side == 1)
		color = (color >> 1) & 8355711;
	my_mlx_pixel_put(&game->img, x, y, color);
}

static void	draw_wall(t_game *game, int x)
{
	int				y;
	t_texture		*texture;

	set_texture_and_step(game, &texture);
	game->rays.tex_pos = (game->rays.draw_start - HEIGHT
			/ 2 + game->rays.line_height / 2) * game->rays.step;
	y = game->rays.draw_start;
	while (y < game->rays.draw_end)
	{
		draw_wall_pixel(game, x, y, texture);
		y++;
	}
}

void	raycaster(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		setup(game, x);
		get_sides(game);
		dda(game);
		prepare_drawing(game);
		if (game->rays.hit > 0)
			draw_wall(game, x);
	}
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.mlx_win,
		game->img.img, 0, 0);
}
