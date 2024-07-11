/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:11:52 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/11 22:11:53 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/cub.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		validate(argv[1]);
		init_game(argv[1]);
	}
	else
		exit(printf("Error\nInvalid number of arguments\n"));
	return (0);
}
