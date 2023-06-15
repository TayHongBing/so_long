/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:19 by jchu              #+#    #+#             */
/*   Updated: 2023/01/16 15:04:58 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strs(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s != '\0')
			s++;
	}
	return (count);
}

char	**ft_free(char **s, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	*newstring(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (ft_substr(str, 0, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	idx;
	size_t	n_strs;
	char	**array;

	n_strs = count_strs(s, c);
	idx = 0;
	array = malloc(sizeof(char *) * (n_strs + 1));
	if (!s || !array)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			array[idx] = newstring(s, c);
			if (idx < n_strs && !array[idx])
				return (ft_free(array, idx + 1));
			idx++;
		}
		while (*s != c && *s)
			s++;
	}
	array[idx] = 0;
	return (array);
}
