/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:58:10 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 00:58:11 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

void	assign_path(t_game *game, char **arr)
{
	if (strcmp(arr[0], "NO") == 0)
		game->map.no = arr[1];
	else if (strcmp(arr[0], "SO") == 0)
		game->map.so = arr[1];
	else if (strcmp(arr[0], "EA") == 0)
		game->map.ea = arr[1];
	else if (strcmp(arr[0], "WE") == 0)
		game->map.we = arr[1];
	else if (strcmp(arr[0], "C") == 0)
		game->map.c = arr[1];
	else if (strcmp(arr[0], "F") == 0)
		game->map.f = arr[1];
}

void	check_path(t_game *game, char *line)
{
	char	**arr;

	if (strncmp(line, "NO ", 3) == 0
		|| strncmp(line, "SO ", 3) == 0
		|| strncmp(line, "EA ", 3) == 0
		|| strncmp(line, "WE ", 3) == 0
		|| strncmp(line, "C ", 2) == 0
		|| strncmp(line, "F ", 2) == 0
		|| line[0] == '1')
	{
		arr = ft_split(line, ' ');
		assign_path(game, arr);
		return ;
	}
	ft_exit(game, "Error\nInvalid Characters\n", 1);
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
	close(fd);
}
