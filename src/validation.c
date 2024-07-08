#include "../include/cub.h"

void validate(char *path)
{
    t_game game;

    if (!check_format(path))
        exit(printf("Error\nInvalid format\n"));
    game.map.grid = read_map(path);
    // if (!surrounded_by_walls(&game))
    //     ft_exit(&game, "Error\nMap is not surrounded by walls\n", 1);
    if (!check_chars(&game))
        ft_exit(&game, "Error\nInvalid characters in map\n", 1);
}

bool check_format(char *line)
{
    int len;

    len = ft_strlen(line);
    if (ft_strncmp(line + len - 4, ".cub", 4))
        return (false);
    return (true);
}

bool surrounded_by_walls(t_game *game)
{
    int i;
    int j;
    int len;
    char *trim;

    i = 0;
    j = 0;
    trim = ft_strtrim(game->map.grid[0], " \t\n");
    while (trim[i])
    {
        if (trim[i] != '1')
        {
            free (trim);
            return (false);
        }
        i++;
    }
    i = 1;
    while (game->map.grid[i + 1])
    {
        trim = ft_strtrim(game->map.grid[i], " \t\n");
        len = ft_strlen(trim);
        if (trim[0] != '1' || trim[len - 1] != '1')
        {
            free (trim);
            return (false);
        }
        free (trim);
        i++;
    }
    j = 0;
    trim = ft_strtrim(game->map.grid[i], " \t\n");
    while (trim[j])
    {
        if (trim[j] != '1')
        {
            free (trim);
            return (false);
        }
        j++;
    }
    free (trim);
    return (true);
}

bool check_chars(t_game *game)
{
    int i;
    int j;
    int n;
    int s;
    int w;
    int e;
    char c;

    n = 0;
    s = 0;
    w = 0;
    e = 0;

    i = 0;
    while (game->map.grid[i])
    {
        j = 0;
        while (game->map.grid[i][j])
        {
            c = game->map.grid[i][j];
            if (c == 'N')
                n++;
            else if (c == 'S')
                s++;
            else if (c == 'E')
                e++;
            else if (c == 'W')
                w++;
            else if (c != '1' && c != '0' && c != '\n' && c != ' ' && c != '\t')
                return (false);
            j++;
        }
        i++;
    }

    if ((n + s + e + w) != 1)
        return (false);

    return (true);
}
