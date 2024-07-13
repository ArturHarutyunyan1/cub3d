/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:47:44 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/13 22:47:45 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

char	**read_map(char *path)
{
	int		fd;
	int		size;
	char	**map;
	char	**final;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(printf("Error\nCan't open map\n"));
	size = get_size(path);
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	read_and_trim_lines(fd, map);
	final = finalize_map(map, size);
	free_matrix(map);
	close(fd);
	return (final);
}

char	*get_trimmed_line(int fd)
{
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trim = ft_strtrim(line, "\t");
	free(line);
	return (trim);
}

char	**allocate_map(int size)
{
	char	**map;

	map = (char **)malloc((size + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}

void	read_and_trim_lines(int fd, char **map)
{
	int		i;
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	trim = ft_strtrim(line, " \t\n");
	i = 0;
	while (trim && trim[0] != '1')
	{
		free(line);
		free(trim);
		line = get_next_line(fd);
		trim = ft_strtrim(line, " \t\n");
	}
	free(trim);
	while (line)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
}

char	**finalize_map(char **map, int size)
{
	char	**trimmed_map;
	char	**final_map;

	trimmed_map = skip_newlines(map, size);
	if (!trimmed_map)
	{
		free_matrix(map);
		return (NULL);
	}
	compare_maps(map, trimmed_map);
	final_map = trim_map(map);
	free_matrix(trimmed_map);
	return (final_map);
}
