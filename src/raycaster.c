#include "../include/cub.h"

static void setup(t_game *game, int x)
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
	if (game->rays.ray_dir_y == 0)
		game->rays.delta_dist_y = 1e30;
	else
		game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
	game->rays.hit = 0;
}

static void get_sides(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = -1;
		game->rays.side_dist_x = (game->player.x - game->rays.map_x) * game->rays.delta_dist_x;
		game->rays.vertical = NORTH;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0 - game->player.x) * game->rays.delta_dist_x;
		game->rays.vertical = SOUTH;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = -1;
		game->rays.side_dist_y = (game->player.y - game->rays.map_y) * game->rays.delta_dist_y;
		game->rays.horizontal = WEST;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0 - game->player.y) * game->rays.delta_dist_y;
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
        if (game->rays.map_x < 0 || game->rays.map_x >= game->map.width || game->rays.map_y < 0 || game->rays.map_y >= game->map.height)
            return;
        if (game->map.grid[game->rays.map_y][game->rays.map_x] == '1')
            game->rays.hit = 1;
    }
}


void draw_walls(int x, t_game *game)
{
    int line_height;
    int draw_start;
    int draw_end;
    int y;
    t_texture *texture;
    double wall_x;
    int tex_x, tex_y;
    double step;
    double tex_pos;

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

    if (game->rays.side == 0)
        wall_x = game->player.y + game->rays.perp_wall_dist * game->rays.ray_dir_y;
    else
        wall_x = game->player.x + game->rays.perp_wall_dist * game->rays.ray_dir_x;
    wall_x -= floor(wall_x);

    // Determine which texture to use based on the wall side
    if (game->rays.side == 0 && game->rays.ray_dir_x > 0)
        texture = &game->textures[0]; // North
    else if (game->rays.side == 0 && game->rays.ray_dir_x < 0)
        texture = &game->textures[1]; // South
    else if (game->rays.side == 1 && game->rays.ray_dir_y > 0)
        texture = &game->textures[2]; // East
    else
        texture = &game->textures[3]; // West

    tex_x = (int)(wall_x * (double)(texture->width));
    if ((game->rays.side == 0 && game->rays.ray_dir_x > 0) || (game->rays.side == 1 && game->rays.ray_dir_y < 0))
        tex_x = texture->width - tex_x - 1;

    step = 1.0 * texture->height / line_height;
    tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;

    for (y = draw_start; y < draw_end; y++)
    {
        tex_y = (int)tex_pos & (texture->height - 1);
        tex_pos += step;
        int color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x * (texture->bpp / 8)));
        mlx_pixel_put(game->vars.mlx, game->vars.mlx_win, x, y, color);
    }
}   

void raycaster(t_game *game)
{
    int x = 0;
    while (x < WIDTH)
    {
        setup(game, x);
        get_sides(game);
        dda(game);
        if (game->rays.hit == 1)
            draw_walls(x, game);
        ++x;
    }
}