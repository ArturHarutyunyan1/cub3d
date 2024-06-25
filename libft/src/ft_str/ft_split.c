/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:58:29 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/22 12:31:54 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*dup;

	if (n < ft_strlen(str))
		len = n;
	else
		len = ft_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memmove(dup, str, len);
	dup[len] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s && *s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		result[i++] = ft_strndup(s, word_len);
		s += word_len;
	}
	result[i] = NULL;
	return (result);
}
