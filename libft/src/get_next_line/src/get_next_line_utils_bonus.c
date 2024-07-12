/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:36:07 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 23:30:05 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/get_next_line_bonus.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*ptr;

	ptr = malloc(items * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, items * size);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc((length + 1) * sizeof(char));
	if (!ret || !s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
