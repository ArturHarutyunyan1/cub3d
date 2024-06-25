/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:06 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 11:58:12 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

static unsigned int	ft_module_fd(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = ft_module_fd(n);
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + 48, fd);
}
