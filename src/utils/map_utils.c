#include "../../include/cub.h"

int get_size(char *path)
{
    int fd;
    int flag;
    int map_size;
    char *line;

    fd = open(path, O_RDONLY);
    flag = 1;
    map_size = 0;
    while (flag)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            if (map_size == 0)
                return (-1);
            flag = 0;
        }
        else
            map_size++;
        free (line);
    }
    close (fd);
    return (map_size);
}

char **read_map(char *path)
{
    int i;
    int fd;
    int count;
    char *line;
    char **map;

    i = 0;
    count = get_size(path);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        exit(printf("Error\nCannot read map!\n"));
    map = (char **)malloc((count + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    line = get_next_line(fd);
    while (line && !(line[0] == '1'))
    {
        free (line);
        line = get_next_line(fd);
    }
    while (line && line[0] == '1')
    {
        map[i] = malloc((ft_strlen(line) + 1));
        if (!map[i])
            free (map);
        ft_strlcpy(map[i], line, ft_strlen(line) + 1);
        i++;
        free (line);
        line = get_next_line(fd);
    }
    map[i] = NULL;
    close (fd);
    return (map);
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
                if (game->map.grid[i][j] == 'N')
                {
                    game->player.dir_x = -1;
                    game->player.dir_y = 0;
                    game->player.plane_x = 0;
                    game->player.plane_y = 0.66;
                }
                else if (game->map.grid[i][j] == 'S')
                {
                    game->player.dir_x = 1;
                    game->player.dir_y = 0;
                    game->player.plane_x = 0;
                    game->player.plane_y = -0.66;
                }
                else if (game->map.grid[i][j] == 'E')
                {
                    game->player.dir_x = 0;
                    game->player.dir_y = 1;
                    game->player.plane_x = 0.66;
                    game->player.plane_y = 0;
                }
                else if (game->map.grid[i][j] == 'W')
                {
                    game->player.dir_x = 0;
                    game->player.dir_y = -1;
                    game->player.plane_x = -0.66;
                    game->player.plane_y = 0;
                }
                return;
            }
            j++;
        }
        i++;
    }
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