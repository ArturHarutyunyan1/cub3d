/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:08 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/13 01:13:10 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../include/cub.h"
void	validate(char *path)
{
	t_game	game;

	if (!check_format(path))
		exit(printf("Error\nInvalid format\n"));
	game.map.grid = read_map(path);
	game.map = init_map(game.map.grid);
	check_map(game.map.grid, 1);
	if (!surrounded_by_walls(&game))
		ft_exit(&game, "Error\nMap is not surrounded by walls\n", 1);
	if (!check_chars(&game, 0, 0, 0))
		ft_exit(&game, "Error\nInvalid characters in map\n", 1);
	free_matrix(game.map.grid);
}

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
		if (trim[i] != '1')
		{
			free(trim);
			return (false);
		}
		i++;
	}
	free(trim);

	i = 0;
	trim = ft_strtrim(game->map.grid[game->map.height], " \t\n");
	if (!trim)
		return (false);
	while (trim[i])
	{
		if (trim[i] != '1')
		{
			free(trim);
			return (false);
		}
		i++;
	}
	free(trim);

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
				&& game->map.grid[i][j] != '\t')
				return (false);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (false);
	return (true);
}
