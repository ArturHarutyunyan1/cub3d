#include "../include/cub.h"

void minimap(t_game *game)
{
    int x;
    int y;
    int map_x;
    int map_y;
    int scale;
    int color;

    scale = 10;
    map_y = 0;
    while (map_y < game->map.height)
    {
        map_x = 0;
        while (map_x < game->map.width)
        {
            if (game->map.grid[map_y][map_x] == '1' || game->map.grid[map_y][map_x] == ' ' || game->map.grid[map_y][map_x] == '\t')
                color = 0x4169E1;
            else if (game->map.grid[map_y][map_x] == '0')
                color = 0x000000;
            y = 0;
            while (y < scale)
            {
                x = 0;
                while (x < scale)
                {
                    my_mlx_pixel_put(&game->img, map_x * scale + x, map_y * scale + y, color);
                    my_mlx_pixel_put(&game->img, (game->player.x - 0.5) * scale + x, (game->player.y - 0.5) * scale + y, 0xFF0000);
                    x++;
                }
                y++;
            }
            map_x++;
        }
        map_y++;
    }
}