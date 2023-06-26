/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:11:52 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/24 12:15:19 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	if_0(t_data *data, int j, int i)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->window.map[y][x] = '0';
	data->window.map[j][i] = 'P';
	data->player.moves++;
}

static void	if_c(t_data *data, int j, int i)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->window.map[y][x] = '0';
	data->window.map[j][i] = 'P';
	data->player.moves++;
	data->window.coin--;
}

static void	if_e(t_data *data, int j, int i)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->window.map[y][x] = '0';
	data->window.map[j][i] = 'E';
	data->player.moves++;
	data->window.end = 1;
}

void	result_key(t_data *data, int j, int i)
{
	if (data->window.map[j][i] == '0')
		if_0(data, j, i);
	else if (data->window.map[j][i] == 'C')
		if_c(data, j, i);
	else if (data->window.map[j][i] == 'E'
		&& data->window.coin == 0)
		if_e(data, j, i);
	else
		return ;
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		game_exit(data);
	else if (data->window.end)
		return (0);
	else
	{
		updater(keycode, data);
		display_info(data);
	}
	return (0);
}
