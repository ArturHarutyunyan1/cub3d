/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:55 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/15 23:50:22 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	init_game(char *argv)
{
	t_game	game;

	ft_memset(game.key_states, 0, sizeof(game.key_states));
	game.map.grid = read_map(argv);
	game.map = init_map(game.map.grid);
	game.map.path = ft_strdup(argv);
	init_rays(&game);
	init_img(&game);
	init_player(&game);
	get_paths(&game, argv);
	game.ceiling = set_colors(game.map.c);
	game.floor = set_colors(game.map.f);
	game.vars.mlx = mlx_init();
	game.vars.mlx_win = mlx_new_window(game.vars.mlx,
			WIDTH, HEIGHT, "Cub3D");
	game.img.img = mlx_new_image(game.vars.mlx, WIDTH, HEIGHT);
	game.img.addr = mlx_get_data_addr(game.img.img,
			&game.img.bits_per_pixel,
			&game.img.line_length,
			&game.img.endian);
	init_textures(&game);
	set_sprite(&game);
	init_mouse(&game);
	mlx_hook(game.vars.mlx_win, 2, 1L << 0, keypress, &game);
	mlx_hook(game.vars.mlx_win, 3, 1L << 1, keyrelease, &game);
	mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
	mlx_loop_hook(game.vars.mlx, game_loop, &game);
	mlx_hook(game.vars.mlx_win, 6, 1L << 6, mouse_move, &game);
	mlx_loop(game.vars.mlx);
}