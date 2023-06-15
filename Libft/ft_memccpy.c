/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:19:21 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:50:32 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	while (n > 0)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			return (d + 1);
		}
		n--;
		s++;
		d++;
	}
	return (NULL);
}
