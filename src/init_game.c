#include "../include/cub.h"

void setup(int x, t_game *game)
{
    game->rays.camera_x = 2 * x / (double)WIDTH - 1;
    game->rays.ray_dir_x = game->player.dir_x + game->player.plane_x * game->rays.camera_x;
    game->rays.ray_dir_y = game->player.dir_y + game->player.plane_y * game->rays.camera_x;
    game->rays.map_x = (int)game->player.x;
    game->rays.map_y = (int)game->player.y;
    if (game->rays.ray_dir_x == 0)
        game->rays.delta_dist_x = 1e30;
    else
        game->rays.delta_dist_x = fabs(1 / game->rays.ray_dir_x);
    if (game->rays.delta_dist_y == 0)
        game->rays.delta_dist_y = 1e30;
    else
        game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
    game->rays.hit = 0;
}

void get_sides(t_game *game)
{
    if (game->rays.ray_dir_x < 0)
    {
        game->rays.step_x = -1;
        game->rays.side_dist_x = (game->player.x - game->rays.map_x) * game->rays.delta_dist_x;
    }
    else
    {
        game->rays.step_x = 1;
        game->rays.side_dist_x = (game->rays.map_x + 1.0 - game->player.x) * game->rays.delta_dist_x;
    }
    if (game->rays.ray_dir_y < 0)
    {
        game->rays.step_y = -1;
        game->rays.side_dist_y = (game->player.y - game->rays.map_y) * game->rays.delta_dist_y;
    }
    else
    {
        game->rays.step_y = 1;
        game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.y) * game->rays.delta_dist_y;
    }
}

void dda(t_game *game)
{
    while (game->rays.hit == 0)
    {
        if (game->rays.side_dist_x < game->rays.side_dist_y)
        {
            game->rays.side_dist_x += game->rays.delta_dist_x;
            game->rays.map_x += game->rays.step_x;
            game->rays.side = 0;
        }
        else
        {
            game->rays.side_dist_y += game->rays.delta_dist_y;
            game->rays.map_y += game->rays.step_y;
            game->rays.side = 1;
        }
        if (game->rays.map_x < 0 || game->rays.map_x >= game->map.width || game->rays.map_y < 0 || game->rays.map_y >= game->map.height)
            return;
        if (game->map.grid[game->rays.map_x][game->rays.map_y] == '1')
            game->rays.hit = 1;
    }
}

void draw_walls(int x, t_game *game)
{
    int line_height;
    int draw_start;
    int draw_end;
    int y;

    if (game->rays.side == 0)
        game->rays.perp_wall_dist = (game->rays.map_x - game->player.x + (1 - game->rays.step_x) / 2) / game->rays.ray_dir_x;
    else
        game->rays.perp_wall_dist = (game->rays.map_y - game->player.y + (1 - game->rays.step_y) / 2) / game->rays.ray_dir_y;

    line_height = (int)(HEIGHT / game->rays.perp_wall_dist);

    draw_start = -line_height / 2 + HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;

    draw_end = line_height / 2 + HEIGHT / 2;
    if (draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;

    for (y = draw_start; y < draw_end; y++)
    {
        mlx_pixel_put(game->vars.mlx, game->vars.mlx_win, x, y, 0x00FF00); // Green color
    }
}

void raycaster(t_game *game)
{
    for (int x = 0; x < WIDTH; x++)
    {
        setup(x, game);
        get_sides(game);
        dda(game);
        if (game->rays.hit)
            draw_walls(x, game);
    }
}

void init_game(char *argv)
{
    t_game game;
    
    game.map.grid = read_map(argv);
    game.map.width = 5;
    game.map.height = 4;
    init_rays(&game);
    init_player(&game);
    game.vars.mlx = mlx_init();
    game.vars.mlx_win = mlx_new_window(game.vars.mlx, WIDTH, HEIGHT, "Cub3D");
    raycaster(&game);
    mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    mlx_loop(game.vars.mlx);
}