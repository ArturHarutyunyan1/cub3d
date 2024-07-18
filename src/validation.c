/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:08 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/18 09:31:50 by arturhar         ###   ########.fr       */
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
		if (trim[i] != '1')
		{
			free(trim);
			return (false);
		}
		i++;
	}
	free(trim);

	i = 0;
	trim = ft_strtrim(game->map.grid[game->map.height - 1], " \t\n");
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

int	check(char s)
{
	if (s == ' ' || s == '\t' || s == '\r' || s == '\n')
		return (1);
	return (0);
}

void	check_map(char **map, size_t i, size_t j)
{
	i = 1;
	while (map[i])
	{
		j = 0;
		if (j < ft_strlen(map[i]) - 1)
		{
			while (map[i][j + 1])
			{
				if ((j > ft_strlen(map[i]) - 1 || j > ft_strlen(map[i - 1]) - 1)
					&& map[i][j] != '1' && check(map[i][j]) == 0)
					exit(printf("Error\nSomething went wrong aaa\n"));
				if (check(map[i][j]) == 1 || map[i][j] == '1')
					j++;
				else if (map[i][j] != '1' && check(map[i][j - 1]) == 0
						&& check(map[i][j + 1]) == 0
						&& check(map[i + 1][j]) == 0
						&& check(map[i - 1][j]) == 0)
					j++;
				else
					exit(printf("Error\nSomething went wrong\n"));
			}
		}
		i++;
	}
}

void iterate_file(t_game *game)
{
	t_list *cur;
	char *trim;

	cur = game->file;
	while (cur)
	{
		trim = ft_strtrim((char *)cur->content, " \t\n");
		if (!contains_only_whitespace(trim) &&!is_identifier(trim) && !is_valid_line(trim))
			ft_exit(game, "Error\nInvalid characters\n", 1);
		free(trim);
		cur = cur->next;
	}
}

void	validate(t_game *game, char *path)
{
	if (!check_format(path))
		exit(printf("Error\nInvalid format\n"));
	iterate_file(game);
	check_map(game->map.grid, 0, 0);
	if (!surrounded_by_walls(game))
		ft_exit(game, "Error\nMap is not surrounded by walls\n", 1);
	if (!check_chars(game, 0, 0, 0))
		ft_exit(game, "Error\nInvalid characters\n", 1);
}
