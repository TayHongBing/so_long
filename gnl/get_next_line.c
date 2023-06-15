/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:47:55 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/27 21:30:45 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		str = ft_strjoin_2(str, buf, bytes);
		if (ft_strchr(str, '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes == -1)
	{
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*res;
	int		n;

	n = 0;
	if (!str || !str[n])
		return (NULL);
	n = ft_line_len(str);
	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	n = 0;
	while (str[n] && str)
	{
		res[n] = str[n];
		n++;
		if (str[n - 1] == '\n')
			break ;
	}
	res[n] = 0;
	return (res);
}

char	*ft_renew(char *str)
{
	int		i;
	int		n;
	int		count;
	char	*res;

	count = 0;
	if (!str || !str[count])
		return (NULL);
	n = ft_strlen(str) - ft_line_len(str);
	if (!n)
	{
		free(str);
		return (NULL);
	}
	res = malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = ft_line_len(str);
	while (count < n)
		res[count++] = str[i++];
	res[count] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	res = ft_get_line(str);
	str = ft_renew(str);
	return (res);
}
