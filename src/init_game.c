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

void draw_floor_and_ceiling(t_game *game)
{
    int x;
    int y;
    int ceiling_color;
    int floor_color;

    ceiling_color = (game->ceiling.r << 16) | (game->ceiling.g << 8) | game->ceiling.b;
    floor_color = (game->floor.r << 16) | (game->floor.g << 8) | game->floor.b;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, ceiling_color);
            x++;
        }
        y++;
    }
    y = HEIGHT / 2;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            my_mlx_pixel_put(&game->img, x, y, floor_color);
            x++;
        }
        y++;
    }
}

int game_loop(t_game *game)
{
    clear_image(game);
    draw_floor_and_ceiling(game);
    update_player(game);
    raycaster(game);
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win, game->img.img, 0, 0);
    return (0);
}

void init_game(char *argv)
{
    t_game game;

    ft_memset(game.key_states, 0, sizeof(game.key_states));
    game.map.grid = read_map(argv);
    game.map = init_map(game.map.grid);
    game.ceiling = (t_color){.r = 255, .g = 0, .b = 0};
    game.floor = (t_color){.r = 0, .g = 255, .b = 0};
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