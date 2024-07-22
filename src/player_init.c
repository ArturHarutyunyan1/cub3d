/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:20:24 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/22 16:19:40 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	set_dir(char c, t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	if (c == 'N')
	{
		game->player.dir_x = -1;
		game->player.plane_y = 0.66;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 1;
		game->player.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		game->player.dir_y = 1;
		game->player.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_y = -1;
		game->player.plane_x = -0.66;
	}
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width && game->map.grid[i][j] != '\0')
		{
			if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'E'
				|| game->map.grid[i][j] == 'W')
			{
				game->player.x = j + 0.5;
				game->player.y = i + 0.5;
				set_dir(game->map.grid[i][j], game);
				game->map.grid[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

t_map	init_map(char **str)
{
	int		i;
	int		current_len;
	int		max_len;
	t_map	map;

	i = 0;
	max_len = 0;
	while (str[i])
	{
		if (str[i][0] == '\n')
			break ;
		current_len = ft_strlen(str[i]);
		if (current_len > max_len)
			max_len = current_len;
		i++;
	}
	map.width = max_len;
	map.height = i;
	map.grid = str;
	return (map);
}
