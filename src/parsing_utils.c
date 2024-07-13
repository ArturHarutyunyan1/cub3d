/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:04:32 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/13 23:06:14 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
