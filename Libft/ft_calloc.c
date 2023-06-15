/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:17:35 by jchu              #+#    #+#             */
/*   Updated: 2023/01/16 15:01:19 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	idx;

	if (size * count >= MAX)
		return (NULL);
	buffer = (void *)malloc(size * count);
	if (!buffer)
		return (NULL);
	idx = 0;
	while (idx < size * count)
		((char *)buffer)[idx++] = 0;
	return (buffer);
}
