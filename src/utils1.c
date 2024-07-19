/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:01:12 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/19 21:15:31 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (str1[i] == str2[i])
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	contains_only_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((char)*str))
			return (0);
		str++;
	}
	return (1);
}

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

void	set_newlines(char **map, int i)
{
	map[i] = ft_strdup("\n");
	map[i + 1] = ft_strdup("\n");
	map[i + 2] = ft_strdup("\n");
	map[i + 3] = NULL;
}
