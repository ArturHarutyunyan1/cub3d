/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:25:42 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/29 21:23:09 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	format_parser(va_list args, const char f)
{
	int	length;

	length = 0;
	if (f == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (f == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		length += ft_putuint(va_arg(args, unsigned int));
	else if (f == 'p' || f == 'x' || f == 'X')
	{
		if (f == 'p')
			length += ft_print_hex(va_arg(args, unsigned long long), f);
		else
			length += ft_print_hex(va_arg(args, unsigned int), f);
	}
	return (length);
}
