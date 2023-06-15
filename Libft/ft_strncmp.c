/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:35 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:21:11 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (s1[idx] && s1[idx] == s2[idx])
			idx++;
		else
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	}
	return (0);
}
