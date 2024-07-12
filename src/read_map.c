#include "../include/cub.h"

char **read_map(char *path)
{
    int fd = open(path, O_RDONLY);
    int size = get_size(path);
    if (fd < 0 || size < 0)
        return NULL;
    char **map = (char **)malloc((size + 1) * sizeof(char *));
    if (!map)
    {
        close(fd);
        return NULL;
    }
    read_and_trim_lines(fd, map);
    char **final = finalize_map(map, size);
    free_matrix(map);
    close(fd);
    return final;
}

char *get_trimmed_line(int fd)
{
    char *line;
    char *trim;

    line = get_next_line(fd);
    if (!line)
        return (NULL);
    trim = ft_strtrim(line, " \t\n");
    free(line);
    return (trim);
}


char **allocate_map(int size) {
    char **map;

    map = (char **)malloc((size + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    return (map);
}

void read_and_trim_lines(int fd, char **map)
{
    int i = 0;
    char *trim;

    trim = get_trimmed_line(fd);
    while (trim && trim[0] != '1')
    {
        free(trim);
        trim = get_trimmed_line(fd);
    }
    while (trim)
    {
        map[i] = trim;
        i++;
        trim = get_trimmed_line(fd);
    }
    map[i] = NULL;
}

char **finalize_map(char **map, int size)
{
    char **trimmed_map = skip_newlines(map, size);
    if (!trimmed_map)
    {
        free_matrix(map);
        return NULL;
    }
    compare_maps(map, trimmed_map);
    char **final_map = trim_map(map);
    free_matrix(trimmed_map);
    return final_map;
}