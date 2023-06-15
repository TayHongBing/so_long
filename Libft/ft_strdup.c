/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:23 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:31:45 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*buffer;
	int		len;

	len = ft_strlen(s1);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		buffer[idx] = s1[idx];
		idx++;
	}
	buffer[idx] = '\0';
	return (buffer);
}
