#include "../include/cub.h"

char **read_map(char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;

    int size = get_size(path);
    char **map = allocate_map(size);
    if (!map) return NULL;

    read_and_trim_lines(fd, map);

    close(fd);

    return finalize_map(map, size);
}

char *get_trimmed_line(int fd) {
    char *line = get_next_line(fd);
    if (!line) return NULL;

    char *trim = ft_strtrim(line, " \t\n");
    free(line);
    return trim;
}

char **allocate_map(int size) {
    char **map = (char **)malloc((size + 1) * sizeof(char *));
    if (!map) return NULL;
    return map;
}

void read_and_trim_lines(int fd, char **map) {
    char *trim = get_trimmed_line(fd);
    int i = 0;

    while (trim && trim[0] != '1') {
        free(trim);
        trim = get_trimmed_line(fd);
    }

    while (trim) {
        map[i] = trim;
        i++;
        trim = get_trimmed_line(fd);
    }
    map[i] = NULL;
}

char **finalize_map(char **map, int size)
{
    char **trimmed_map = skip_newlines(map, size);
    compare_maps(map, trimmed_map);
    return trim_map(map);
}