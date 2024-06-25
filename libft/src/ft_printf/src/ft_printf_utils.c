/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:37:37 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/29 21:22:59 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	reverse(const char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		ft_putchar(str[i--]);
	}
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int nb)
{
	char	*num;
	int		length;

	length = 0;
	num = ft_itoa(nb);
	length += ft_putstr(num);
	free (num);
	return (length);
}

unsigned int	ft_putuint(unsigned int n)
{
	char	digit;
	char	buffer[20];
	int		length;

	length = 0;
	digit = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n != 0)
	{
		digit = n % 10;
		buffer[length] = digit + '0';
		n /= 10;
		length++;
	}
	buffer[length] = '\0';
	reverse(buffer);
	return (length);
}
