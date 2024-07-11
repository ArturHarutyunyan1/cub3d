#include "../include/cub.h"

int	get_size(char *path)
{
	int		fd;
	int		flag;
	int		map_size;
	char	*line;

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
		free(line);
	}
	close(fd);
	return (map_size);
}

char	**trim_map(char **map)
{
	int i;
	int size;
	char **trim;

	i = 0;
	size = 0;
	while (map[size] && map[size][0] != '\n')
		size++;
	trim = (char **)malloc((size + 3) * sizeof(char *));
	if (!trim)
		return (NULL);
	while (i < size)
	{
		trim[i] = map[i];
		i++;
	}
	trim[size] = strdup("\n");
	trim[size + 1] = strdup("\n");
	trim[size + 2] = NULL;
	return (trim);
}

char	**skip_newlines(char **map, int size)
{
	int i;
	int j;
	char *trimmed_line;
	char **trim;
	
	i = 0;
	j = 0;
	trim = (char **)malloc((size + 1) * sizeof(char *));
	if (!trim)
		return (NULL);
	while (map[i]) {
		trimmed_line = ft_strtrim(map[i], " \t\n");
		if (trimmed_line[0] != '\0') {
			trim[j] = strdup(map[i]);
			j++;
		}
		free(trimmed_line);
		i++;
	}
	return (trim);
}

void	compare_maps(char **map, char **trim)
{
	int i;

	i = 0;
	while (map[i] && trim[i])
	{
		if (strcmp(map[i], trim[i]) != 0)
		{
			exit(printf("Error\nNewline encountered\n"));
		}
		i++;
	}
}