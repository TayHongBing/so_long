/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:11:44 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/04 15:44:45 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *data)
{
	data->collect = 0;
	data->move = 0;
	data->width = ft_strlen(data->map[0]);
	data->height = get_height(data->map);
}

int	quit_game(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		free(data->map[x]);
		x++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
	return (0);
}

void	update_move(t_data *data)
{
	int		width;
	int		height;
	char	*text;
	char	*num;

	num = ft_itoa(data->move++);
	text = ft_strjoin("Move: ", num);
	data->img = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm",
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 50 * 2, 0);
	mlx_string_put(data->mlx, data->win, 5, 10, 0xfffffff, text);
	printf("%s\n", num);
	free(text);
	free(num);
}
