/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:16:56 by thong-bi          #+#    #+#             */
/*   Updated: 2023/06/26 14:40:52 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_location(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		result_key(data, data->player.y - 1, data->player.x);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		result_key(data, data->player.y, data->player.x + 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		result_key(data, data->player.y + 1, data->player.x);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		result_key(data, data->player.y, data->player.x - 1);
	else
		return ;
}

void	update_direction(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		data->player.player_direc = 'w';
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		data->player.player_direc = 'a';
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		data->player.player_direc = 's';
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		data->player.player_direc = 'd';
	else
		return ;
}

void	map_hook_p(t_data *data, int j, int i)
{
	img_draw(data, data->img.player_s, j, i);
	data->player.x = j;
	data->player.y = i;
}
