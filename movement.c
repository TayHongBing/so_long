/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:08 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/04 17:20:59 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_collect(t_data *data)
{
	int	width;
	int	height;

	data->collect--;
	data->map[(data->player_y / 50)][(data->player_x / 50)] = '0';
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
}

void	move_left(t_data *data)
{
	int	width;
	int	height;

	data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
	if (data->map[(data->player_y / 50)][(data->player_x / 50) - 1] == 'E')
	{
		if (data->collect <= 0)
			door_open(data);
	}
	else if (data->map[(data->player_y / 50)][(data->player_x / 50) - 1] == '1')
	{
		data->player_x -= 50;
		update_move(data);
	}
	if (data->map[(data->player_y / 50)][(data->player_x / 50) - 1] == 'C')
		update_collect(data);
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/left.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
}

void	move_right(t_data *data)
{
	int	width;
	int	height;

	data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
	if (data->map[(data->player_y / 50)][(data->player_x / 50) + 1] == 'E')
	{
		if (data->collect <= 0)
			door_open(data);
	}
	else if (data->map[(data->player_y / 50)][(data->player_x / 50) + 1] == '1')
	{
		data->player_x += 50;
		update_move(data);
	}
	if (data->map[(data->player_y / 50)][(data->player_x / 50) + 1] == 'C')
		update_collect(data);
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/right.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
}

void	move_up(t_data *data)
{
	int	width;
	int	height;

	data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
	if (data->map[(data->player_y / 50) - 1][(data->player_x / 50)] == 'E')
	{
		if (data->collect <= 0)
			door_open(data);
	}
	else if (data->map[(data->player_y / 50) - 1][(data->player_x / 50)] == '1')
	{
		data->player_y -= 50;
		update_move(data);
	}
	if (data->map[(data->player_y / 50) - 1][(data->player_x / 50)] == 'C')
		update_collect(data);
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/back.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
}

void	move_down(t_data *data)
{
	int	width;
	int	height;

	data->img = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
	if (data->map[(data->player_y / 50) + 1][(data->player_x / 50)] == 'E')
	{
		if (data->collect <= 0)
			door_open(data);
	}
	else if (data->map[(data->player_y / 50) + 1][(data->player_x / 50)] == '1')
	{
		data->player_y += 50;
		update_move(data);
	}
	if (data->map[(data->player_y / 50) + 1][(data->player_x / 50)] == 'C')
		update_collect(data);
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/front.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->player_x, data->player_y);
}
