#include "../../include/cub.h"

bool	surrounded_by_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (false);
		j++;
	}
	i++;
	len = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void exit_program(char *msg, int status)
{
    printf("%s", msg);
    exit (status);
}