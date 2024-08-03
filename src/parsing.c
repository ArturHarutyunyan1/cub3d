/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:42:56 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/03 09:46:19 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	set_counts(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		game->valid.count_no++;
	else if (ft_strncmp(line, "SO", 2) == 0)
		game->valid.count_so++;
	else if (ft_strncmp(line, "EA", 2) == 0)
		game->valid.count_ea++;
	else if (ft_strncmp(line, "WE", 2) == 0)
		game->valid.count_we++;
	else if (ft_strncmp(line, "C", 1) == 0)
		game->valid.count_c++;
	else if (ft_strncmp(line, "F", 1) == 0)
		game->valid.count_f++;
	if (game->valid.count_no > 1 || game->valid.count_so > 1
		|| game->valid.count_ea > 1
		|| game->valid.count_we > 1
		|| game->valid.count_c > 1
		|| game->valid.count_f > 1)
		ft_exit(game, "Error\nSomething went wrong with paths\n", 1);
}

void	set_paths(t_game *game, char *line)
{
	char	**elements;

	elements = ft_split(line, ' ');
	if (!elements || !elements[1] || elements[2])
	{
		free_matrix(elements);
		exit(printf("Error\nSomething went wrong\n"));
		return ;
	}
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
	char	*dup;
	char	*trimmed_line;

	dup = ft_strtrim(line, " \t\n");
	trimmed_line = malloc(ft_strlen(dup) + 1);
	if (trimmed_line)
	{
		remove_extra_spaces(dup, trimmed_line);
		set_counts(game, trimmed_line);
		set_paths(game, trimmed_line);
		free(trimmed_line);
	}
	else
	{
		free (trimmed_line);
		ft_exit(game, "Error\nMemory allocation failure\n", 1);
	}
	free (dup);
}

void	extract_paths(t_game *game)
{
	char	*line;
	t_list	*cur;

	cur = game->file;
	while (cur)
	{
		line = ft_strtrim((char *)cur->content, " \t\n");
		if (!contains_only_whitespace((char *)cur->content)
			&& is_identifier(line))
			process_line(game, (char *)cur->content);
		free (line);
		cur = cur->next;
	}
	if (game->valid.count_no != 1 || game->valid.count_so != 1
		|| game->valid.count_ea != 1
		|| game->valid.count_we != 1
		|| game->valid.count_c != 1
		|| game->valid.count_f != 1)
		exit(printf("Error\nSomething went wrong with paths\n"));
}
