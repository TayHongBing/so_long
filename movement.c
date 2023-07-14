/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:08 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/05 18:34:17 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_collect(t_data ***data)
{
	int	width;
	int	height;

	(**data)->collect--;
	(**data)->map[((**data)->player_y / 50)][((**data)->player_x / 50)] = '0';
	(**data)->img = mlx_xpm_file_to_image((**data)->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img,
		(**data)->player_x, (**data)->player_y);
}

void	move_left(t_data **d)
{
	int	width;
	int	height;

	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50) - 1] == 'E')
	{
		if ((*d)->collect <= 0)
			door_open(&d);
	}
	else if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50) - 1] != '1')
	{
		(*d)->player_x -= 50;
		update_move(&d);
	}
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50)] == 'C')
		update_collect(&d);
	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/left.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
}

void	move_right(t_data **d)
{
	int	width;
	int	height;

	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50) + 1] == 'E')
	{
		if ((*d)->collect <= 0)
			door_open(&d);
	}
	else if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50) + 1] != '1')
	{
		(*d)->player_x += 50;
		update_move(&d);
	}
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50)] == 'C')
		update_collect(&d);
	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/right.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
}

void	move_up(t_data **d)
{
	int	width;
	int	height;

	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
	if ((*d)->map[((*d)->player_y / 50) - 1][((*d)->player_x / 50)] == 'E')
	{
		if ((*d)->collect <= 0)
			door_open(&d);
	}
	else if ((*d)->map[((*d)->player_y / 50) - 1][((*d)->player_x / 50)] != '1')
	{
		(*d)->player_y -= 50;
		update_move(&d);
	}
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50)] == 'C')
		update_collect(&d);
	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/back.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
}

void	move_down(t_data **d)
{
	int	width;
	int	height;

	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/floor.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
	if ((*d)->map[((*d)->player_y / 50) + 1][((*d)->player_x / 50)] == 'E')
	{
		if ((*d)->collect <= 0)
			door_open(&d);
	}
	else if ((*d)->map[((*d)->player_y / 50) + 1][((*d)->player_x / 50)] != '1')
	{
		(*d)->player_y += 50;
		update_move(&d);
	}
	if ((*d)->map[((*d)->player_y / 50)][((*d)->player_x / 50)] == 'C')
		update_collect(&d);
	(*d)->img = mlx_xpm_file_to_image((*d)->mlx, "./img/front.xpm",
			&width, &height);
	mlx_put_image_to_window((*d)->mlx, (*d)->win, (*d)->img,
		(*d)->player_x, (*d)->player_y);
}
