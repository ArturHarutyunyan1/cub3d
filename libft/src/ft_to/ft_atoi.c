/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:10:46 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/20 17:25:19 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] == ' ' || (str[i] == '\n') || (str[i] == '\t')
			|| (str[i] == '\v') || (str[i] == '\f') || str[i] == '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

//int main()
//{
//printf("ft - %d\nlib - %d\n", ft_atoi(""), atoi(""));
//printf("ft - %d\nlib - %d\n", ft_atoi("0"), atoi("0"));
//printf("ft - %d\nlib - %d\n", ft_atoi("123456798123"), atoi("123456798123"));
//printf("ft - %d\nlib - %d\n", ft_atoi("0.4987"), atoi("0.4987"));
//}