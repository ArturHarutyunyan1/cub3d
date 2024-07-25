/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:05:19 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/25 21:08:06 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	check_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ',')
			exit(printf("Error\nSomething went wrong\n"));
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		exit(printf("Error\nSomething went wrong\n"));
}
