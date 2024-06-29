#include "../include/cub.h"



void init_game(char *argv)
{
    t_game game;
    
    game.map.grid = read_map(argv);
    game.map = init_map(game.map.grid);
    init_rays(game);
    init_player(&game);
    game.vars.mlx = mlx_init();
    game.vars.mlx_win = mlx_new_window(game.vars.mlx, WIDTH, HEIGHT, "Cub3D");
    mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    mlx_loop(game.vars.mlx);
}