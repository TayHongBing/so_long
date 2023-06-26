/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:10:28 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/31 16:07:27 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_updater(t_data *data, int j, int i)
{
	if (data->player.player_direc == 'w')
		img_draw(data, data->img.player_w, j, i);
	else if (data->player.player_direc == 'a')
		img_draw(data, data->img.player_a, j, i);
	else if (data->player.player_direc == 's')
		img_draw(data, data->img.player_s, j, i);
	else if (data->player.player_direc == 'd')
		img_draw(data, data->img.player_d, j, i);
	data->player.x = j;
	data->player.y = i;
}

static void	map_updater(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->window.map[i])
	{
		j = 0;
		while (data->window.map[i][j])
		{
			if (data->window.map[i][j] == '1')
				img_draw(data, data->img.img_w, j, i);
			else if (data->window.map[i][j] == '0')
				img_draw(data, data->img.img_s, j, i);
			else if (data->window.map[i][j] == 'E')
				img_draw(data, data->img.img_e, j, i);
			else if (data->window.map[i][j] == 'C')
				img_draw(data, data->img.img_c, j, i);
			else if (data->window.map[i][j] == 'P')
				player_updater(data, j, i);
			j++;
		}
		i++;
	}
}

void	updater(int keycode, t_data *data)
{
	update_direction(keycode, data);
	update_location(keycode, data);
	map_updater(data);
}
