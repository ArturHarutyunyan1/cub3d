#include "../../include/cub.h"

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

char	**read_map(char *path)
{
	int		i;
	int		fd;
	int		size;
	char	*line;
	t_game	game;

	i = 0;
	size = get_size(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_program("Error\nCannot open file!\n", 1);
	game.map = (char **)malloc((size + 1) * sizeof(char *));
	if (!game.map)
		return (NULL);
	while (i < size)
	{
		line = get_next_line(fd);
		game.t_line = ft_strtrim(line, "\n\t ");
		game.map[i] = malloc(ft_strlen(game.t_line) + 1);
		ft_strlcpy(game.map[i], game.t_line, ft_strlen(game.t_line) + 1);
		free(game.t_line);
		i++;
		free(line);
	}
	game.map[i] = NULL;
	return (game.map);
}

t_map	get_dimensions(char **str)
{
	int		i;
	int		len;
	t_map	map;

	i = 0;
	map.rows = 0;
	map.cols = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (len != 0)
		{
			if (len > map.cols)
				map.cols = len;
			map.rows++;
		}
		i++;
	}
	return (map);
}


void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}