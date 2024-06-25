/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:26:01 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 11:54:24 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
		str[i++] = 0;
}

//int main()
//{
//    char str[13] = "Hello Vaspur";
//    ft_bzero(str, 5);
//    printf("%s", str);
//    return (0);
//}