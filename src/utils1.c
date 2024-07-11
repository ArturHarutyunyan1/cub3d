#include "../include/cub.h"

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