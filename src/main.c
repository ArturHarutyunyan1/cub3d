/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:11:52 by arturhar          #+#    #+#             */
/*   Updated: 2024/08/16 14:18:09 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(game));
		read_file_into(&game.file, argv[1]);
		extract_map(&game, argv[1]);
		game.map = init_map(game.map.grid);
		validate(&game, argv[1]);
		init_game(&game);
	}
	else
		exit(printf("Error\nInvalid arguments\n"));
	return (0);
}
