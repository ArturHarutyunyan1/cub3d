#include "../include/cub.h"

int	check(char s)
{
	if (s == ' ' || s == '\t' || s == '\r' || s == '\n')
		return (1);
	return (0);
}

void check_map(char **map)
{
    size_t i;
    size_t j;

    i = 1;
	while (map[i])
	{
		j = 1;
		if (j < ft_strlen(map[i]) - 1)
		{
			while (map[i][j + 1])
			{
				if ((j > ft_strlen(map[i]) - 1 || j > ft_strlen(map[i - 1]) - 1)
					&& map[i][j] != '1' && check(map[i][j]) == 0)
                    exit(printf("Error\nSomething went wrong\n"));
				if (check(map[i][j]) == 1 || map[i][j] == '1')
					j++;
				else if (map[i][j] != '1' && check(map[i][j - 1]) == 0
					&& check(map[i][j + 1]) == 0 && check(map[i + 1][j]) == 0
					&& check(map[i - 1][j]) == 0)
					j++;
				else
                    exit(printf("Error\nSomething went wrong\n"));
			}
		}
		i++;
	}
}

int get_size(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0) return -1;

    int flag = 1;
    int map_size = 0;
    char *line;

    while (flag)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            if (map_size == 0) return -1;
            flag = 0;
        }
        else
        {
            map_size++;
            free(line);
        }
    }
    close(fd);
    return map_size;
}

char **trim_map(char **map)
{
    int size = 0;
    while (map[size] && map[size][0] != '\n')
        size++;
    char **trim = (char **)malloc((size + 3) * sizeof(char *));
    if (!trim) return NULL;

    for (int i = 0; i < size; i++) {
        trim[i] = map[i];
    }
    
    trim[size] = strdup("\n");
    trim[size + 1] = strdup("\n");
    trim[size + 2] = NULL;
    return trim;
}

char **skip_newlines(char **map, int size) {
    char **trim = (char **)malloc((size + 1) * sizeof(char *));
    if (!trim) return NULL;

    int i = 0, j = 0;
    while (map[i]) {
        char *trimmed_line = ft_strtrim(map[i], " \t\n");
        if (trimmed_line[0] != '\0') {
            trim[j] = strdup(map[i]);
            j++;
        }
        free(trimmed_line);
        i++;
    }
    return trim;
}

void compare_maps(char **map, char **trim) {
    int i = 0;
    while (map[i] && trim[i]) {
        if (strcmp(map[i], trim[i]) != 0) {
            exit(printf("Error\nNewline encountered\n"));
        }
        i++;
    }
}


char **read_map(char *path)
{
    int i;
    int fd;
    int size;
    char *line;
    char *trim;
    char **map;
    char **trimmed_map;

    i = 0;
    fd = open(path, O_RDONLY);
    size = get_size(path);
    map = (char **)malloc((size + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    line = get_next_line(fd);
    trim = ft_strtrim(line, " \t\n");
    while (trim[0] != '1')
    {
        free (trim);
        free (line);
        line = get_next_line(fd);
        trim = ft_strtrim(line, " \t\n");
    }
    while (line)
    {
        map[i] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
        if (!map[i])
            return (NULL);
        ft_strlcpy(map[i], line, ft_strlen(line) + 1);
        i++;
        free (line);
        line = get_next_line(fd);
    }
    map[i] = NULL;
    trimmed_map = skip_newlines(map, size);
    compare_maps(map, trimmed_map);
    return(trim_map(map));
}
