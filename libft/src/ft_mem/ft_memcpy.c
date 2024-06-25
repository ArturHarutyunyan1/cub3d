/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:55:32 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 11:55:51 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if ((dest == src) || n == 0)
		return (dest);
	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int main() {
//     const char src[20] = "Hello";

//     memcpy(src + 3, src, sizeof(src));
//     printf("%s", src);

//     return 0;
// }