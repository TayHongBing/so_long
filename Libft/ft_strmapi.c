/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:33 by jchu              #+#    #+#             */
/*   Updated: 2023/03/25 00:39:56 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	idx;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!s || !f || !temp)
		return (NULL);
	idx = 0;
	while (idx < ft_strlen((char *)s))
	{
		temp[idx] = f(idx, s[idx]);
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
