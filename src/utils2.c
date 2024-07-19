/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:16:00 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/19 21:21:16 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

int	is_identifier(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "C", 1) == 0
		|| ft_strncmp(line, "F", 1) == 0)
		return (1);
	return (0);
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

void	iterate_file(t_game *game)
{
	t_list	*cur;
	char	*trim;

	cur = game->file;
	while (cur)
	{
		trim = ft_strtrim((char *)cur->content, " \t\n");
		if (!contains_only_whitespace(trim)
			&& !is_identifier(trim) && !is_valid_line(trim))
			ft_exit(game, "Error\nInvalid characters\n", 1);
		free(trim);
		cur = cur->next;
	}
}
