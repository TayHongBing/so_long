/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:37 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:20:29 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	if (!len)
		return (NULL);
	count = ft_strlen((char *)needle);
	while (*haystack != '\0' && len-- >= count)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, count) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

/*int main()
{
	char *str;
	str = ft_strnstr(0, "fake", 0);
	return (0);
}*/