/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:14:07 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:18:31 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// int main()
// {
// 	char s[35] = "Hello Movses, this is Gaspar";
// 	int c = 'G';
// 	char *ret, *ret1;	
// 	ret = ft_memchr(s, c, sizeof(s));
// 	ret1 = ft_memchr(s, c, sizeof(s));

// 	printf("ft - %s\nlib - %s\n", ret, ret1);
// }
