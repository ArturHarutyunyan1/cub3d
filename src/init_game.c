#include "../include/cub.h"

void raycasting(t_game *game)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
        // calculate ray position and drection
        game->rays.camera_x = 2 * x / (double)WIDTH - 1;
        game->rays.ray_dir_x = game->player.dir_x + game->player.plane_x * game->rays.camera_x;
        game->rays.ray_dir_y = game->player.dir_y + game->player.plane_y * game->rays.camera_x;
        // //which box of the map we're in
        game->rays.map_x = (int)game->player.dir_x;
        game->rays.map_y = (int)game->player.dir_y;
        //length of ray from one x or y-side to next x or y-side
        game->rays.delta_dist_x = sqrt(1 + (game->rays.ray_dir_y * game->rays.ray_dir_y) / (game->rays.ray_dir_x * game->rays.ray_dir_x));
        game->rays.delta_dist_y = sqrt(1 + (game->rays.ray_dir_x * game->rays.ray_dir_x) / (game->rays.ray_dir_y * game->rays.ray_dir_y));
        //calculate step and initial sideDist
        if (game->rays.ray_dir_x < 0)
        {
            game->rays.step_x = -1;
            game->rays.side_dist_x = (game->player.dir_x - game->rays.map_x) * game->rays.delta_dist_x;
        }
        else
        {
            game->rays.step_x = 1;
            game->rays.side_dist_y = (game->rays.map_x + 1.0 - game->player.dir_x);
        }
        if (game->rays.ray_dir_y < 0)
        {
            game->rays.step_y = -1;
            game->rays.side_dist_y = (game->player.dir_y - game->rays.map_y) * game->rays.delta_dist_y;
        }
        else
        {
            game->rays.step_y = 1;
            game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.dir_y) * game->rays.delta_dist_y;
        }
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
            if (game->map.grid[game->rays.map_x][game->rays.map_y] == '1')
                game->rays.hit = 1;
        }
        x++;
    }
}

void init_game(char *argv)
{
    t_game game;
    
    game.map.grid = read_map(argv);
    printf("%s", game.map.grid[0]);
    game.map = init_map(game.map.grid);
    init_rays(game);
    init_player(&game);
    game.vars.mlx = mlx_init();
    game.vars.mlx_win = mlx_new_window(game.vars.mlx, WIDTH, HEIGHT, "Cub3D");
    mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    mlx_loop(game.vars.mlx);
}