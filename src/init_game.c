#include "../include/cub.h"

int keypress(int code, t_game *game)
{
    if (code == KEY_ESC)
        exit_game(game);
    else if (code == KEY_W)
    {
        game->player.x += game->player.dir_x * MOVE_SPEED;
        game->player.y += game->player.dir_y * MOVE_SPEED;
    }
    mlx_clear_window(game->vars.mlx, game->vars.mlx_win);
    raycaster(game);
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win, game->img.img, 0, 0);
    return (0);
}

void init_game(char *argv)
{
    t_game game;

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
    raycaster(&game);
    mlx_hook(game.vars.mlx_win, 2, 1L << 0, keypress, &game);
    mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    mlx_loop(game.vars.mlx);
}
