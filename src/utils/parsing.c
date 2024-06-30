#include "../../include/cub.h"

void check_path(t_game *game, char *line)
{
    int i;
    char **arr;
    char *prefixes[4];

    i = 0;
    prefixes[0] = "NO";
    prefixes[1] = "SO";
    prefixes[2] = "EA";
    prefixes[3] = "WE";
    while (prefixes[i])
    {
        if (ft_strncmp(line, prefixes[i], 2) == 0)
        {
            arr = ft_split(line, ' ');
            if (arr)
            {
                if (i <= 3)
                {
                    if (i == 0)
                        game->map.no = arr[1];
                    else if (i == 1)
                        game->map.so = arr[1];
                    else if (i == 2)
                        game->map.ea = arr[1];
                    else if (i == 3)
                        game->map.we = arr[1];
                }
                if (game->map.no && game->map.so && game->map.ea && game->map.we)
                    game->map.is_all_set = 1;
                return;
            }
        }
        i++;
    }
}

void process_line(t_game *game, char *line)
{
    int i;
    int j;
    int flg;
    char *dup;
    char *trimmed_line;

    i = 0;
    j = 0;
    flg = 0;
    dup = ft_strtrim(line, " \t");
    trimmed_line = malloc(ft_strlen(dup) + 1);
    if (trimmed_line)
    {
        while (dup[i])
        {
            if (dup[i] == ' ' || dup[i] == '\t')
            {
                if (flg == 0)
                {
                    trimmed_line[j++] = ' ';
                    flg = 1;
                }
            }
            else
            {
                trimmed_line[j++] = dup[i];
                flg = 0;
            }
            i++;
        }
        trimmed_line[j] = '\0';
        check_path(game, trimmed_line);
        free(dup);
        free(trimmed_line);
    }
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	contains_only_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((char)*str))
			return (0);
		str++;
	}
	return (1);
}

void get_paths(t_game *game, char *path)
{
    int fd;
    char *line;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return;
    game->map.is_all_set = 0;
    while (game->map.is_all_set != 1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (!contains_only_whitespace(line))
            process_line(game, line);
        free(line);
    }
    close(fd);
}
