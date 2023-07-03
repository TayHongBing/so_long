/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:50:44 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/03 15:00:04 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		move_right(data);
	else if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 13 || keycode == 126)
		move_up(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 53)
	{
		x = 0;
		while (data->map[x])
		{
			free(data->map[x]);
			x++;
		}
		free(data->map);
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}