/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:16:40 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/25 17:08:14 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)ptr1;
	str2 = (const unsigned char *)ptr2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char ptr1[30] = "Hello nigger";
// 	char ptr2[30] = "jello nigger";

// 	printf("%d", ft_memcmp(ptr1, ptr2, sizeof(ptr1)));
// }