#include "../include/cub.h"

void	setup(t_game *game, int x)
{
	game->rays.camera_x = 2 * x / (double)WIDTH - 1;
	game->rays.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->rays.camera_x;
	game->rays.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->rays.camera_x;
	game->rays.map_x = (int)game->player.x;
	game->rays.map_y = (int)game->player.y;
	if (game->rays.ray_dir_x == 0)
		game->rays.delta_dist_x = 1e30;
	else
		game->rays.delta_dist_x = fabs(1 / game->rays.ray_dir_x);
	if (game->rays.ray_dir_y == 0)
		game->rays.delta_dist_y = 1e30;
	else
		game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
	game->rays.hit = 0;
}

void	get_sides(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player.x - game->rays.map_x)
			* game->rays.delta_dist_x;
		game->rays.vertical = NORTH;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0 - game->player.x)
			* game->rays.delta_dist_x;
		game->rays.vertical = SOUTH;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player.y - game->rays.map_y)
			* game->rays.delta_dist_y;
		game->rays.horizontal = WEST;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.y)
			* game->rays.delta_dist_y;
		game->rays.horizontal = EAST;
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
		if (game->rays.map_x < 0 || game->rays.map_x >= game->map.width
			|| game->rays.map_y < 0
			|| game->rays.map_y >= game->map.height)
			return ;
		if (game->map.grid[game->rays.map_y][game->rays.map_x] == '1')
			game->rays.hit = 1;
	}
}


void calculate_perp_wall_dist_and_direction(t_game *game)
{
    if (game->rays.side == 0)
    {
        game->rays.perp_wall_dist = game->rays.side_dist_x
            - game->rays.delta_dist_x;
        game->rays.direction = game->rays.vertical;
    }
    else
    {
        game->rays.perp_wall_dist = game->rays.side_dist_y
            - game->rays.delta_dist_y;
        game->rays.direction = game->rays.horizontal;
    }
    game->rays.line_height = (int)(HEIGHT / game->rays.perp_wall_dist);
    game->rays.draw_start = -game->rays.line_height / 2 + HEIGHT / 2;
    if (game->rays.draw_start < 0)
        game->rays.draw_start = 0;
    game->rays.draw_end = game->rays.line_height / 2 + HEIGHT / 2;
    if (game->rays.draw_end >= HEIGHT)
        game->rays.draw_end = HEIGHT - 1;
}

void calculate_draw_limits_and_tex_x(t_game *game)
{
    if (game->rays.side == 0)
    {
        game->rays.wall_x = game->player.y + game->rays.perp_wall_dist
            * game->rays.ray_dir_y;
    }
    else
    {
        game->rays.wall_x = game->player.x + game->rays.perp_wall_dist
            * game->rays.ray_dir_x;
    }
    game->rays.wall_x -= floor(game->rays.wall_x);
    game->rays.tex_x = (int)(game->rays.wall_x
            * (double)game->textures[0].width);
    if (game->rays.side == 0 && game->rays.ray_dir_x > 0)
        game->rays.tex_x = game->textures[0].width - game->rays.tex_x - 1;
    if (game->rays.side == 1 && game->rays.ray_dir_y < 0)
        game->rays.tex_x = game->textures[0].width - game->rays.tex_x - 1;
}