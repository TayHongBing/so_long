/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ani_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:12:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/12 16:20:23 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check(t_data ***data, int x, int y)
{
	if ((**data)->map[y][x] == '0' && (**data)->map[y][x + 1] == '0'
		&& (**data)->map[y][x + 2] == '0')
	{
		(**data)->e_data.sign = 0;
		(**data)->e_data.enemy_x = x;
		(**data)->e_data.enemy_y = y;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_data **data)
{
	int			y;
	int			x;
	int			height;

	y = 0;
	height = get_height((*data)->map);
	if ((*data)->e_data.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*data)->map[y][x] != '\0')
			{
				if (check(&data, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	open_exit(t_data **data)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*data)->map);
	while (y != height)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'E')
			{
				(*data)->img = mlx_xpm_file_to_image(
						(*data)->mlx, "./img2/exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*data)->mlx, (*data)->win, (*data)->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
