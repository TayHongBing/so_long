/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:19:55 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 20:53:39 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d > s)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}

/*
char str[] = "Hello, world!";
memmove(str + 7, str, 5);
*/