#include "../include/cub.h"

int keypress(int code, t_game *game)
{
    if (code == KEY_ESC)
        exit_game(game);
    else if (code == KEY_W)
    {
        double new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
        double new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
        if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
            game->player.y = new_y;
        if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
            game->player.x = new_x;
    }
    else if (code == KEY_S)
    {
        double new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
        double new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
        if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
            game->player.y = new_y;
        if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
            game->player.x = new_x;
    }
    else if (code == KEY_A)
    {
        double new_x = game->player.x - game->player.plane_x * MOVE_SPEED;
        double new_y = game->player.y - game->player.plane_y * MOVE_SPEED;
        if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
            game->player.y = new_y;
        if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
            game->player.x = new_x;
    }
    else if (code == KEY_D)
    {
        double new_x = game->player.x + game->player.plane_x * MOVE_SPEED;
        double new_y = game->player.y + game->player.plane_y * MOVE_SPEED;
        if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
            game->player.y = new_y;
        if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
            game->player.x = new_x;
    }
    else if (code == LEFT_ARROW)
    {
        double old_dir_x = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(-ROTATE_SPEED) - game->player.dir_y * sin(-ROTATE_SPEED);
        game->player.dir_y = old_dir_x * sin(-ROTATE_SPEED) + game->player.dir_y * cos(-ROTATE_SPEED);
        double old_plane_x = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(-ROTATE_SPEED) - game->player.plane_y * sin(-ROTATE_SPEED);
        game->player.plane_y = old_plane_x * sin(-ROTATE_SPEED) + game->player.plane_y * cos(-ROTATE_SPEED);
    }
    else if (code == RIGHT_ARROW)
    {
        double old_dir_x = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(ROTATE_SPEED) - game->player.dir_y * sin(ROTATE_SPEED);
        game->player.dir_y = old_dir_x * sin(ROTATE_SPEED) + game->player.dir_y * cos(ROTATE_SPEED);
        double old_plane_x = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(ROTATE_SPEED) - game->player.plane_y * sin(ROTATE_SPEED);
        game->player.plane_y = old_plane_x * sin(ROTATE_SPEED) + game->player.plane_y * cos(ROTATE_SPEED);
    }
    clear_image(game);  // Clear the image buffer
    raycaster(game);    // Render the new frame
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win, game->img.img, 0, 0);  // Display the new frame
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
