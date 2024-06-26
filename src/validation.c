#include "../include/cub.h"

void	validation(int argc, char **argv)
{
	t_game	game;
	t_map	dimensions;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		dimensions = get_dimensions(game.map);
		game.map_height = dimensions.rows;
		game.map_width = dimensions.cols;
		check_format(argv[1]);
		validate_map(argv[1]);
		if (!surrounded_by_walls(game.map))
			exit_program("Error\nMap is not surrounded by walls!\n", 1);
		free_matrix(game.map);
	}
	else
		exit_program("Error\nInvalid number of arguments", 1);
}

bool check_format(char *path)
{
    const char *dot;

    dot = ft_strchr(path, '.');
    if (dot != NULL && ft_strncmp(dot, ".cub", 4) == 0)
        return (true);
    return (false);
}

void	check_chars(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return ;
	else
		exit_program("Error\nInvalid characters\n", 1);
}

void	validate_map(char *path)
{
	int		i;
	int		j;
	t_game	game;

	i = 0;
	game.map = read_map(path);
	if (!game.map)
		exit(2);
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			check_chars(game.map[i][j]);
			j++;
		}
		i++;
	}
	free_matrix(game.map);
}