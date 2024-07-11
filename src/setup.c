#include "../include/cub.h"

void check_inits(t_game *game) {
    if (!game->map.ea || !game->map.so || !game->map.we || !game->map.no ||
        !game->map.c || !game->map.f) {
        ft_exit(game, "Error\nNot all required paths are initialized\n", 1);
    }
}

t_color set_colors(char *str)
{
    char **rgb;
    t_color color;
    int i;

    rgb = ft_split(str, ',');
    color.r = ft_atoi(rgb[0]);
    color.g = ft_atoi(rgb[1]);
    color.b = ft_atoi(rgb[2]);
    i = 0;
    while (rgb[i])
    {
        free(rgb[i]);
        i++;
    }
    free(rgb);
    return (color);
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