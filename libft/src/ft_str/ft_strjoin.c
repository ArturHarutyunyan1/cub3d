/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:01:46 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 12:05:17 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	rtn = malloc(sizeof(char) * (len));
	if (rtn == NULL)
		return (NULL);
	ft_memmove(rtn, s1, ft_strlen(s1));
	ft_memmove(rtn + ft_strlen(s1), s2, ft_strlen(s2));
	rtn[len - 1] = '\0';
	return (rtn);
}
