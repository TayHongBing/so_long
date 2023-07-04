/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:12:55 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/04 17:10:54 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data, char *err)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		free(data->map[x]);
		x++;
	}
	free(data->map);
	printf("%s", err);
	exit(1);
}
