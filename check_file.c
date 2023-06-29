/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:40:42 by thong-bi          #+#    #+#             */
/*   Updated: 2023/06/20 15:19:30 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file)
{
	char	*extension;

	if (!file)
		exit(1);
	extension = ft_strrchr(file, '.');
	if (ft_strncmp(extension, ".ber", 5))
		return ;
	printf("ERROR: file is not valid");
	exit(1);
}