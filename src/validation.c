/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:08 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/07 13:51:23 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

bool	check_format(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strncmp(line + len - 4, ".cub", 4))
		return (false);
	return (true);
}

bool	surrounded_by_walls(t_game *game)
{
	int		i;
	char	*trim;

	i = 0;
	trim = ft_strtrim(game->map.grid[0], " \t\n");
	if (!trim)
		return (false);
	while (trim[i])
	{
		if (trim[i] != '1' && trim[i] != ' ' && trim[i] != '\t')
			return (false);
		i++;
	}
	i = 0;
	free (trim);
	trim = ft_strtrim(game->map.grid[game->map.height], " \t\n");
	while (trim[i])
	{
		if (trim[i] != '1' && trim[i] != ' ' && trim[i] != '\t')
			return (false);
		i++;
	}
	free (trim);
	return (true);
}

bool	check_chars(t_game *game, int i, int j, int count)
{
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (game->map.grid[i][j] == 'N'
				|| game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'W'
				|| game->map.grid[i][j] == 'E')
				count++;
			else if (game->map.grid[i][j] != '1' && game->map.grid[i][j] != '0'
				&& game->map.grid[i][j] != '\n' && game->map.grid[i][j] != ' '
				&& game->map.grid[i][j] != '\t' && game->map.grid[i][j] != 'D'
				&& game->map.grid[i][j] != 'd')
				return (false);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (false);
	return (true);
}

void	check_doors(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'D' || game->map.grid[y][x] == 'd')
			{
				if (!(game->map.grid[y][x - 1] == '1'
					&& game->map.grid[y][x + 1] == '1')
					&& !(game->map.grid[y - 1][x] == '1'
					&& game->map.grid[y + 1][x] == '1'))
					ft_exit(game, "Error\nInvalid door\n", 1);
			}
			x++;
		}
		y++;
	}
}

void	validate(t_game *game, char *path)
{
	t_map	map;

	if (!check_format(path))
		exit(printf("Error\nInvalid format\n"));
	iterate_file(game);
	map.dup = dup_map(game->map.grid);
	check_map(map.dup, 0, 0);
	check_doors(game);
	if (!surrounded_by_walls(game))
		ft_exit(game, "Error\nMap is not surrounded by walls\n", 1);
	if (!check_chars(game, 0, 0, 0))
		ft_exit(game, "Error\nInvalid characters\n", 1);
	free_matrix(map.dup);
}
