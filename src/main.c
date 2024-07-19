/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:11:52 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/19 21:55:00 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	set_all_to_zero(t_game *game)
{
	game->valid.count_c = 0;
	game->valid.count_f = 0;
	game->valid.count_ea = 0;
	game->valid.count_so = 0;
	game->valid.count_no = 0;
	game->valid.count_we = 0;
	game->file = NULL;
	game->map.grid = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		set_all_to_zero(&game);
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
