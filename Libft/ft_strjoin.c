/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:25 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:27:35 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		total_len;
	int		idx_new;
	int		idx;

	idx_new = 0;
	idx = 0;
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	newstring = (char *)malloc(sizeof(char) * (total_len));
	if (!newstring)
		return (NULL);
	while (s1[idx])
		newstring[idx_new++] = s1[idx++];
	idx = 0;
	while (s2[idx])
		newstring[idx_new++] = s2[idx++];
	newstring[idx_new] = '\0';
	return (newstring);
}
