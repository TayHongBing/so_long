/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:27 by jchu              #+#    #+#             */
/*   Updated: 2023/03/25 00:42:42 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	idx;
	int	src_idx;
	int	value;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		value = ft_strlen(src) + dstsize;
	else
		value = ft_strlen(src) + ft_strlen(dst);
	src_idx = 0;
	idx = 0;
	while (dst[idx] != '\0')
		idx++;
	while (src[src_idx] && dstsize > idx + 1)
	{
		dst[idx] = src[src_idx];
		idx++;
		src_idx++;
	}
	dst[idx] = '\0';
	return (value);
}
