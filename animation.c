/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/05 18:38:52 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_data **data)
{
	int			img_w;
	int			img_h;

	(*data)->e_data.imgs[0] = "./img/1.xpm";
	(*data)->e_data.imgs[1] = "./img/2.xpm";
	(*data)->e_data.imgs[2] = "./img/3.xpm";
	(*data)->e_data.imgs[3] = "./img/2.xpm";
	(*data)->e_data.imgs[4] = "./img/1.xpm";
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img,
		(*data)->e_data.enemy_x * 50, (*data)->e_data.enemy_y * 50);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, (*data)->e_data.imgs[(*data)->e_data.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img,
		(*data)->e_data.enemy_x * 50, (*data)->e_data.enemy_y * 50);
}

void	move_enemy(t_data **d)
{
	int			img_w;
	int			img_h;

	(*d)->img = mlx_xpm_file_to_image(
			(*d)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*d)->mlx, (*d)->win, (*d)->img,
		(*d)->e_data.enemy_x * 50, (*d)->e_data.enemy_y * 50);
	if ((*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x + 1] != '1' &&
		(*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x + 1] != 'C' &&
		(*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x + 1] != 'E' &&
		(*d)->e_data.path == 0)
		(*d)->e_data.enemy_x++;
	else
		(*d)->e_data.path = 1;
	if ((*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x - 1] != '1' &&
		(*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x - 1] != 'C' &&
		(*d)->map[(*d)->e_data.enemy_y][(*d)->e_data.enemy_x - 1] != 'E' &&
		(*d)->e_data.path == 1)
		(*d)->e_data.enemy_x--;
	else
		(*d)->e_data.path = 0;
}

static void	ft_lose(t_data **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	printf("%s", err);
	exit(0);
}

int	animation(t_data *data)
{
	if (get_position_for_enemy(&data) != 0)
	{
		if (data->e_data.sleep-- <= 0)
		{
			data->e_data.x++;
			data->e_data.sleep = 5;
		}
		if (data->e_data.x == 3)
			data->e_data.x = 0;
		if (data->e_data.sleep_for_move-- <= 0)
		{
			move_enemy(&data);
			data->e_data.sleep_for_move = 30;
		}
		if ((data->e_data.enemy_y == data->player_y / 50)
			&& (data->e_data.enemy_x == data->player_x / 50))
		{
			ft_lose(&data, "You Lose :(");
		}
		render_img(&data);
	}
	if (data->collect <= 0)
		open_exit(&data);
	return (0);
}
