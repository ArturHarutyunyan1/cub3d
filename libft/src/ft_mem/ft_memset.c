/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:56:23 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 11:57:07 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	*ft_memset(void *ptr, int value, size_t	n)
{
	unsigned char	val;
	char			*str;
	size_t			i;

	i = 0;
	str = (char *)ptr;
	val = (unsigned char)value;
	while (i < n)
		str[i++] = val;
	return (str);
}
