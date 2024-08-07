/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:47:44 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/07 13:52:17 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_size(char *path)
{
	int		fd;
	int		flag;
	int		map_size;
	char	*line;

	flag = 1;
	map_size = 0;
	fd = open(path, O_RDONLY);
	while (flag)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (map_size == 0)
				return (-1);
			flag = 0;
		}
		else
		{
			map_size++;
			free(line);
		}
	}
	close(fd);
	return (map_size);
}

void	read_file_into(t_list **file, char *path)
{
	int		fd;
	char	*line;
	t_list	*node;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(printf("Error\nCan't open file\n"));
	line = get_next_line(fd);
	while (line)
	{
		node = (t_list *)malloc((ft_strlen(line) + 1) * sizeof(t_list));
		if (!node)
			exit(printf("Error\nMemory allocation failure\n"));
		node->content = ft_strdup(line);
		node->next = NULL;
		ft_lstadd_back(file, node);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}

int	is_valid_line(char *line)
{
	char	*trim;

	trim = ft_strtrim(line, " \n\t");
	if (trim[0] == '1')
	{
		free (trim);
		return (1);
	}
	free (trim);
	return (0);
}

void	check_for_valid_map(t_list *cur)
{
	char	*line;
	int		found_empty_line;
	int		found_valid_map_start;

	found_empty_line = 0;
	found_valid_map_start = 0;
	while (cur)
	{
		line = (char *)cur->content;
		if (contains_only_whitespace(line))
		{
			if (found_valid_map_start)
				found_empty_line = 1;
		}
		else if (is_valid_line(line))
		{
			if (found_empty_line)
				exit(printf("Error\nEmpty line found\n"));
			found_valid_map_start = 1;
		}
		cur = cur->next;
	}
	if (!found_valid_map_start)
		exit(printf("Error\nMissing map\n"));
}

void	extract_map(t_game *game, char *path)
{
	int		i;
	char	*line;
	t_list	*cur;

	i = 0;
	game->map.grid = (char **)malloc((get_size(path) + 4) * sizeof(char *));
	if (!game->map.grid)
		ft_exit(game, "Error\nMemory allocation failure\n", 1);
	cur = game->file;
	while (cur)
	{
		line = (char *)cur->content;
		if (!contains_only_whitespace(line) && is_valid_line(line))
		{
			game->map.grid[i] = ft_strdup(line);
			if (!game->map.grid[i])
				return ;
			i++;
		}
		cur = cur->next;
	}
	set_newlines(game->map.grid, i);
	check_for_valid_map(game->file);
}
