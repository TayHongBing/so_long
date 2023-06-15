/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:19:53 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:39:11 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	if (dst == src || !n)
		return (dst);
	idx = 0;
	while (idx < n)
	{
		*((char *)dst + idx) = *((char *)src + idx);
		idx++;
	}
	return (dst);
}
