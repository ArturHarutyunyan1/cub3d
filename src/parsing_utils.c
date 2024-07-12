/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:04:32 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/13 01:09:53 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub.h"

void	remove_extra_spaces(char *dup, char *trimmed_line)
{
	int	i;
	int	j;
	int	flg;

	i = 0;
	j = 0;
	flg = 0;
	while (dup[i])
	{
		if ((dup[i] == ' ' || dup[i] == '\t') && flg == 0)
		{
			trimmed_line[j++] = ' ';
			flg = 1;
		}
		else if (dup[i] != ' ' && dup[i] != '\t')
		{
			trimmed_line[j++] = dup[i];
			flg = 0;
		}
		i++;
	}
	trimmed_line[j] = '\0';
}

void	check_and_process_path(t_game *game, char *trimmed_line)
{
	check_path(game, trimmed_line);
}

void	trim_and_process_line(t_game *game, char *dup, char *trimmed_line)
{
	remove_extra_spaces(dup, trimmed_line);
	check_and_process_path(game, trimmed_line);
}

void	process_line(t_game *game, char *line)
{
	char	*dup;
	char	*trimmed_line;

	dup = ft_strtrim(line, " \t\n");
	trimmed_line = malloc(ft_strlen(dup) + 1);
	if (trimmed_line)
	{
		trim_and_process_line(game, dup, trimmed_line);
		free(trimmed_line);
	}
}
