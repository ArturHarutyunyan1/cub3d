#include "../include/cub.h"

static char *set_path(t_game *game, int i)
{
    char *path;

    if (i == 0)
        path = "./textures/sprite0.xpm";
    if (i == 1)
        path = "./textures/sprite1.xpm";
    if (i == 2)
        path = "./textures/sprite2.xpm";
    if (i == 3)
        path = "./textures/sprite3.xpm";
    if (!path)
        ft_exit(game, "Error\nCan't load texture\n", 1);
    return (path);
}

void set_sprite(t_game *game)
{
    int i;
    char *path;

    i = 0;
    while (i <= 3)
    {
        path = set_path(game, i);
        game->sprite[i].img = mlx_xpm_file_to_image(game->vars.mlx, path, &game->sprite[i].width, &game->sprite[i].height);
        if (!game->sprite[i].img)
            ft_exit(game, "Error\nCan't load sprite\n", 1);
        game->sprite[i].addr = mlx_get_data_addr(game->sprite[i].img, &game->sprite[i].bpp, &game->sprite[i].line_length, &game->sprite[i].endian);
        i++;
    }
}

t_texture get_sprite(t_game *game)
{
    static int i;

    i++;
    if (i <= 10)
        return (game->sprite[0]);
    if (i <= 20)
        return (game->sprite[1]);
    if (i <= 30)
        return (game->sprite[2]);
    if (i <= 40)
        return (game->sprite[3]);
    if (i > 40)
        i = 0;
    return (game->sprite[0]);
}

void draw_sprite(t_game *game)
{
    int sprite_width;
    int sprite_height;
    int x_start;
    int y_start;
    int color;
    t_texture sprite;

    sprite_width = 256;
    sprite_height = 256;
    x_start = (WIDTH - sprite_width) / 2;
    y_start = HEIGHT - sprite_height + 10;
    sprite = get_sprite(game);
    for (int y = 0; y < sprite_height; y++)
    {
        for (int x = 0; x < sprite_width; x++)
        {
            color = *(int *)(sprite.addr + (y * sprite.line_length + x * (sprite.bpp / 8)));
            my_mlx_pixel_put(&game->img, x_start + x, y_start + y, color);
        }
    }
}