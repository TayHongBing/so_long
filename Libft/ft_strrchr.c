/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:38 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:19:29 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = ft_strlen((char *)s) + 1;
	while (idx--)
	{
		if (*(s + idx) == (unsigned char)c)
			return ((char *)(s + idx));
	}
	return (NULL);
}
