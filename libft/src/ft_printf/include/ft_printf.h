/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:35:51 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/29 21:25:33 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../../include/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				format_parser(va_list args, const char f);
int				ft_putchar(int c);
int				ft_putstr(const char *str);
int				ft_hex_len(unsigned long long hex);
int				ft_print_hex(unsigned long long hex, const char f);
int				ft_putnbr(int nb);
unsigned int	ft_putuint(unsigned int n);

void			ft_put_hex(unsigned long long hex, const char f);
void			reverse(const char *str);

#endif
