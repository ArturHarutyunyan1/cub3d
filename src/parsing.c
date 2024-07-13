/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:42:56 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/13 22:42:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

void	check_path(t_game *game, char *line)
{
	char	**elements;

	elements = ft_split(line, ' ');
	if (!elements)
		return ;
	if (ft_strncmp(elements[0], "NO", 2) == 0)
		game->map.no = ft_strdup(elements[1]);
	else if (ft_strncmp(elements[0], "SO", 2) == 0)
		game->map.so = ft_strdup(elements[1]);
	else if (ft_strncmp(elements[0], "WE", 2) == 0)
		game->map.we = ft_strdup(elements[1]);
	else if (ft_strncmp(elements[0], "EA", 2) == 0)
		game->map.ea = ft_strdup(elements[1]);
	else if (ft_strncmp(elements[0], "F", 1) == 0)
		game->map.f = ft_strdup(elements[1]);
	else if (ft_strncmp(elements[0], "C", 1) == 0)
		game->map.c = ft_strdup(elements[1]);
	free_matrix(elements);
}

void	process_line(t_game *game, char *line)
{
	int		i;
	int		j;
	int		flg;
	char	*dup;
	char	*trimmed_line;

	i = 0;
	j = 0;
	flg = 0;
	dup = ft_strtrim(line, " \t\n");
	trimmed_line = malloc(ft_strlen(dup) + 1);
	if (trimmed_line)
	{
		remove_extra_spaces(dup, trimmed_line);
		trimmed_line[j] = '\0';
		check_path(game, trimmed_line);
		free(dup);
		free(trimmed_line);
	}
}

void	get_paths(t_game *game, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	game->map.is_all_set = 0;
	while (game->map.is_all_set != 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!contains_only_whitespace(line))
			process_line(game, line);
		free(line);
	}
	free (line);
	close(fd);
}
