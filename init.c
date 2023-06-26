/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:52:55 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/31 03:47:03 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->window.height = data->window.row * SPRITE_SIZE;
	data->window.width = data->window.col * SPRITE_SIZE;
	data->window.win_ptr = mlx_new_window(data->mlx_ptr, data->window.width,
			data->window.height, "so_long");
	data->player.moves = 0;
	data->player.player_direc = 'd';
	data->window.end = 0;
}

static void	*img_initializer(t_data *data, char *img)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img,
			&data->img.width, &data->img.height);
	return (img_ptr);
}

void	init_img(t_data *data)
{
	data->img.img_c = img_initializer(data, IMG_C);
	data->img.img_s = img_initializer(data, IMG_S);
	data->img.img_w = img_initializer(data, IMG_W);
	data->img.img_e = img_initializer(data, IMG_E);
	data->img.img_p = img_initializer(data, IMG_P);
	data->img.player_w = img_initializer(data, IMG_P_W);
	data->img.player_a = img_initializer(data, IMG_P_A);
	data->img.player_s = img_initializer(data, IMG_P_S);
	data->img.player_d = img_initializer(data, IMG_P_D);
}

void	init_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->window.row)
	{
		j = 0;
		while (j < data->window.col)
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
				map_hook_p(data, j, i);
			j++;
		}
		i++;
	}
}

void	initializer(t_data *data)
{
	init_data(data);
	init_img(data);
	init_map(data);
}
