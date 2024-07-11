#include "../include/cub.h"

int	check(char s)
{
	if (s == ' ' || s == '\t' || s == '\r' || s == '\n')
		return (1);
	return (0);
}

void	check_map(char **map)
{
	size_t	i;
	size_t	j;

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
				else if (map[i][j] != '1'
						&& check(map[i][j - 1]) == 0
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