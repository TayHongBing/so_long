/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:05:35 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/27 21:30:10 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin_2(char *s1, char *s2, int bytes)
{
	char	*res;
	int		i;
	int		n;

	i = 0;
	n = 0;
	res = malloc((ft_strlen(s1) + bytes + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[n])
		{
			res[n] = s1[n];
			n++;
		}
		free(s1);
	}
	while (bytes > 0)
	{
		res[n++] = s2[i++];
		bytes--;
	}
	res[n] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!str && !c)
		return ((char *)str);
	return (NULL);
}

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	return (i);
}
