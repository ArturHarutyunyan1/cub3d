/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:39:51 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/03 01:15:24 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_color	set_colors(char *str)
{
	int		i;
	char	**rgb;
	t_color	color;

	check_commas(str);
	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		exit(printf("Error\nSomething went wrong\n"));
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	if (color.r > 255 || color.g > 255 || color.b > 255)
		exit(printf("Error\nSomething went wrong\n"));
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	if (i != 3)
		exit(printf("Error\nSomething went wrong\n"));
	free(rgb);
	return (color);
}

void	init_img(t_game *game)
{
	game->img.bits_per_pixel = 0;
	game->img.endian = 0;
	game->img.line_length = 0;
}

void	init_rays(t_game *game)
{
	game->rays.camera_x = 0;
	game->rays.camera_y = 0;
	game->rays.ray_dir_x = 0;
	game->rays.ray_dir_y = 0;
	game->rays.delta_dist_x = 0;
	game->rays.delta_dist_y = 0;
	game->rays.side_dist_x = 0;
	game->rays.perp_wall_dist = 0;
	game->rays.map_x = 0;
	game->rays.map_y = 0;
	game->rays.step_x = 0;
	game->rays.step_y = 0;
	game->rays.hit = 0;
	game->rays.side = 0;
}

char	*set_path(int i, char *path, t_game *game)
{
	if (i == 0)
	{
		path = game->map.no;
		if (!path)
			ft_exit(game, "Error\nFailed to load north texture\n", 1);
	}
	if (i == 1)
		path = game->map.ea;
	if (i == 2)
		path = game->map.we;
	if (i == 3)
		path = game->map.so;
	if (i == 4)
		path = "./textures/close.xpm";
	if (i == 5)
		path = "./textures/open.xpm";
	if (!path)
		ft_exit(game, "Error\nSomething went wrong with paths\n", 1);
	return (path);
}

void	init_textures(t_game *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i <= 5)
	{
		path = set_path(i, path, game);
		game->textures[i].img = mlx_xpm_file_to_image(game->vars.mlx, path,
				&game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img)
			ft_exit(game, "Error\nFailed to load texture\n", 1);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bpp,
				&game->textures[i].line_length,
				&game->textures[i].endian);
		i++;
	}
}
