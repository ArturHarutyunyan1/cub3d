#include "../include/cub.h"


int keypress(int code, t_game *game)
{
    if (code >= 0 && code < KEY_COUNT)
        game->key_states[code] = 1;
    if (code == KEY_ESC)
        exit_game(game);
    return (0);
}

int keyrelease(int code, t_game *game)
{
    if (code >= 0 && code < KEY_COUNT)
        game->key_states[code] = 0;
    return (0);
}

int game_loop(t_game *game)
{
    clear_image(game);
    update_player(game);
    raycaster(game);
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win, game->img.img, 0, 0);  // Display the new frame
    return (0);
}

void init_game(char *argv)
{
    t_game game;

    ft_memset(game.key_states, 0, sizeof(game.key_states));
    game.map.grid = read_map(argv);
    game.map = init_map(game.map.grid);
    init_rays(&game);
    init_img(&game);
    init_player(&game);
    get_paths(&game, argv);
    game.vars.mlx = mlx_init();
    game.vars.mlx_win = mlx_new_window(game.vars.mlx, WIDTH, HEIGHT, "Cub3D");
    game.img.img = mlx_new_image(game.vars.mlx, WIDTH, HEIGHT);
    game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
    init_textures(&game);
    mlx_hook(game.vars.mlx_win, 2, 1L << 0, keypress, &game);
    mlx_hook(game.vars.mlx_win, 3, 1L << 1, keyrelease, &game);
    mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    mlx_loop_hook(game.vars.mlx, game_loop, &game);
    mlx_loop(game.vars.mlx);
}