#include "../../include/cub.h"

static int get_size(char *path)
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
    int size;
    char *line;
    t_game game;

    i = 0;
    size = get_size(path);
    game.map.grid = (char **)malloc((size + 1) * sizeof(char *));
    fd = open(path, O_RDONLY);
    if (!game.map.grid)
        return (NULL);
    while (i < size)
    {
        line = get_next_line(fd);
        game.map.grid[i] = malloc(ft_strlen(line) + 1);
        ft_strlcpy(game.map.grid[i], line, ft_strlen(line) + 1);
        i++;
        free (line);
    }
    game.map.grid[i] = NULL;
    return (game.map.grid);
}

t_map init_map(char **str)
{
    int i;
    int len;
    t_map map;

    i = 0;
    map.widht = 0;
    map.height = 0;
    while (str[i])
    {
        len = ft_strlen(str[i]);
        if (len != 0)
        {
            if (len > map.widht)
                map.widht = len;
            map.height++;
        }
        i++;
    }
    map.widht -= 1;
    return (map);
}

void init_player(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map.grid[i])
    {
        j = 0;
        while (game->map.grid[i][j])
        {
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
            j++;
        }
        i++;
    }
}