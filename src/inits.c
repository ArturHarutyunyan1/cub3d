#include "../include/cub.h"

void set_dir(char c, t_game *game)
{
    game->player.dir_x = 0;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0;
    if (c == 'N')
    {
        game->player.dir_x = -1;
        game->player.plane_y = 0.66;
    }
    else if (c == 'S')
    {
        game->player.dir_x = 1;
        game->player.plane_y = -0.66;
    }
    else if (c == 'E')
    {
        game->player.dir_y = 1;
        game->player.plane_x = 0.66;
    }
    else if (c == 'W')
    {
        game->player.dir_y = -1;
        game->player.plane_x = -0.66;
    }
}

void init_player(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map.height)
    {
        j = 0;
        while (j < game->map.width)
        {
            if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' || game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
            {
                game->player.x = j + 0.5;
                game->player.y = i + 0.5;
                set_dir(game->map.grid[i][j], game);
                game->map.grid[i][j] = '0';
                return;
            }
            j++;
        }
        i++;
    }
}

t_map init_map(char **str)
{
    int i;
    int len;
    t_map map;

    len = ft_strlen(str[0]);
    i = 0;
    while (str[i])
        i++;
    map.width = len - 1;
    map.height = i;
    map.grid = str;
    return (map);
}

void init_img(t_game *game)
{
    game->img.bits_per_pixel = 0;
    game->img.endian = 0;
    game->img.line_length = 0;
}

void init_rays(t_game *game)
{
    game->rays.camera_x = 0;
    game->rays.camera_y = 0;
    game->rays.ray_dir_x = 0;
    game->rays.ray_dir_y = 0;
    game->rays.delta_dist_x = 0;
    game->rays.delta_dist_y = 0;
    game->rays.side_dist_x = 0;
    game->rays.perp_wall_dist = 0;
    game->rays.map_x = 0;
    game->rays.map_y = 0;
    game->rays.step_x = 0;
    game->rays.step_y = 0;
    game->rays.hit = 0;
    game->rays.side = 0;
}

void init_textures(t_game *game)
{
    game->textures[0].img = mlx_xpm_file_to_image(game->vars.mlx, game->map.no, &game->textures[0].width, &game->textures[0].height);
    if (!game->textures[0].img)
        ft_exit(game, "Failed to load north texture\n",1);
    game->textures[0].addr = mlx_get_data_addr(game->textures[0].img, &game->textures[0].bpp, &game->textures[0].line_length, &game->textures[0].endian);

    game->textures[1].img = mlx_xpm_file_to_image(game->vars.mlx, game->map.ea, &game->textures[1].width, &game->textures[1].height);
    if (!game->textures[1].img)
        ft_exit(game, "Failed to load east texture\n", 1);
    game->textures[1].addr = mlx_get_data_addr(game->textures[1].img, &game->textures[1].bpp, &game->textures[1].line_length, &game->textures[1].endian);

    game->textures[2].img = mlx_xpm_file_to_image(game->vars.mlx, game->map.we, &game->textures[2].width, &game->textures[2].height);
    if (!game->textures[2].img)
        ft_exit(game, "Failed to load west texture\n", 1);
    game->textures[2].addr = mlx_get_data_addr(game->textures[2].img, &game->textures[2].bpp, &game->textures[2].line_length, &game->textures[2].endian);

    game->textures[3].img = mlx_xpm_file_to_image(game->vars.mlx, game->map.so, &game->textures[3].width, &game->textures[3].height);
    if (!game->textures[3].img)
        ft_exit(game, "Failed to load south texture\n",1);
    game->textures[3].addr = mlx_get_data_addr(game->textures[3].img, &game->textures[3].bpp, &game->textures[3].line_length, &game->textures[3].endian);

}
