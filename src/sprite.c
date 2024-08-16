/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:38:29 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/16 14:21:05 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static char	*set_sprite_textures(t_game *game, int i)
{
	char	*path;

	if (i == 0)
		path = ft_strdup("./textures/sprite0.xpm");
	if (i == 1)
		path = ft_strdup("./textures/sprite1.xpm");
	if (i == 2)
		path = ft_strdup("./textures/sprite2.xpm");
	if (i == 3)
		path = ft_strdup("./textures/sprite3.xpm");
	if (i == 4)
		path = ft_strdup("./textures/sprite4.xpm");
	if (!path)
		ft_exit(game, "Error\nCan't load textures\n", 1);
	return (path);
}

void	set_sprite(t_game *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 5)
	{
		path = set_sprite_textures(game, i);
		game->sprite[i].img = mlx_xpm_file_to_image(game->vars.mlx, path,
				&game->sprite[i].width, &game->sprite[i].height);
		free (path);
		if (!game->sprite[i].img)
			ft_exit(game, "Error\nCan't load sprite\n", 1);
		game->sprite[i].addr = mlx_get_data_addr(game->sprite[i].img,
				&game->sprite[i].bpp,
				&game->sprite[i].line_length, &game->sprite[i].endian);
		i++;
	}
}

static t_texture	get_sprite(t_game *game)
{
	static int	i;

	i++;
	if (i <= 10)
		return (game->sprite[0]);
	if (i <= 20)
		return (game->sprite[1]);
	if (i <= 30)
		return (game->sprite[2]);
	if (i <= 40)
		return (game->sprite[3]);
	if (i <= 50)
		return (game->sprite[4]);
	if (i > 50)
	{
		i = 0;
		game->is_animation_playing = 0;
	}
	return (game->sprite[0]);
}

void	sprite(t_game *game, int x, int y)
{
	int			color;
	int			x_start;
	int			y_start;
	t_texture	sprites;

	x_start = (WIDTH - 345) / 2;
	y_start = (HEIGHT - 360) + 10;
	if (!game->is_animation_playing)
		sprites = game->sprite[0];
	else
		sprites = get_sprite(game);
	while (y < 360)
	{
		x = 0;
		while (x < 345)
		{
			color = *(int *)(sprites.addr
					+ (y * sprites.line_length
						+ x * (sprites.bpp / 8)));
			my_mlx_pixel_put(&game->img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}
