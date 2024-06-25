/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:17:47 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 12:17:53 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	c;
	size_t	d;

	if ((src == NULL || dest == NULL) && n == 0)
		return (0);
	if (n <= ft_strlen(dest))
		return (n + ft_strlen(src));
	c = ft_strlen(dest);
	d = 0;
	while (src[d] != 0 && c + 1 < n)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = 0;
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}
