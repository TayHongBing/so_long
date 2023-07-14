/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:17:39 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/05 15:12:55 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data ***data, int x, int y, char *img)
{
	int	width;
	int	height;

	(**data)->img = mlx_xpm_file_to_image((**data)->mlx, img, &width, &height);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img, x, y);
}

void	put_to_map(char position, int x, int y, t_data **data)
{
	if (position == '1')
		put_image(&data, x, y, "./img/wall.xpm");
	else if (position == 'C')
	{
		put_image(&data, x, y, "./img/floor.xpm");
		put_image(&data, x, y, "./img/coin.xpm");
		(*data)->collect++;
	}
	else if (position == 'E')
		put_image(&data, x, y, "./img/exit.xpm");
	else if (position == 'P')
	{
		(*data)->player_y = y;
		(*data)->player_x = x;
		put_image(&data, x, y, "./img/floor.xpm");
		put_image(&data, x, y, "./img/front.xpm");
	}
	else
		put_image(&data, x, y, "./img/floor.xpm");
}

void	render_map(t_data *data)
{
	int	y;
	int	map_y;
	int	check_w;
	int	x;
	int	map_x;

	y = 0;
	map_y = 0;
	check_w = data->width;
	while (data->height > 0)
	{
		x = 0;
		map_x = 0;
		while (data->width > 0)
		{
			put_to_map(data->map[map_y][map_x], x, y, &data);
			map_x++;
			x += 50;
			data->width--;
		}
		data->width = check_w;
		map_y++;
		y += 50;
		data->height--;
	}
}
