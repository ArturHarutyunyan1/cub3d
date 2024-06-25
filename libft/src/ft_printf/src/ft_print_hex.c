/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:29:12 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/29 21:23:04 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_len(unsigned long long hex)
{
	int	length;

	length = 0;
	while (hex != 0)
	{
		hex /= 16;
		length++;
	}
	return (length);
}

void	ft_put_hex(unsigned long long hex, const char f)
{
	if (hex >= 16)
	{
		ft_put_hex(hex / 16, f);
		ft_put_hex(hex % 16, f);
	}
	else
	{
		if (hex <= 9)
			ft_putchar(hex + '0');
		else
		{
			if (f == 'X')
				ft_putchar((hex - 10) + 'A');
			else
				ft_putchar((hex - 10) + 'a');
		}
	}
}

int	ft_print_hex(unsigned long long hex, const char f)
{
	int	length;

	length = 0;
	if (hex == 0 && f == 'p')
	{
		ft_putstr("0x0");
		return (3);
	}
	else if (hex == 0 && f != 'p')
	{
		ft_putchar('0');
		return (1);
	}
	if (f == 'p')
		length += ft_putstr("0x");
	ft_put_hex(hex, f);
	length += ft_hex_len(hex);
	return (length);
}
