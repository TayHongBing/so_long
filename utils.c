/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:24:25 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/31 15:52:46 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook_all(t_data *data)
{
	mlx_hook(data->window.win_ptr, 2, 1L << 0, &key_press, data);
	mlx_hook(data->window.win_ptr, 17, 0, &game_exit, data);
}

int	display_info(t_data *data)
{
	printf("Your moves: %d\n", data->player.moves);
	return (1);
}

void	free_map(t_data *data)
{
	int	i;

	if (!data->window.map)
		return ;
	i = 0;
	while (i < data->window.row)
	{
		free(data->window.map[i]);
		data->window.map[i] = NULL;
		i++;
	}
	free(data->window.map);
	data->window.map = NULL;
}

void	free_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_c);
	mlx_destroy_image(data->mlx_ptr, data->img.img_e);
	mlx_destroy_image(data->mlx_ptr, data->img.img_w);
	mlx_destroy_image(data->mlx_ptr, data->img.img_s);
	mlx_destroy_image(data->mlx_ptr, data->img.img_p);
	mlx_destroy_image(data->mlx_ptr, data->img.player_a);
	mlx_destroy_image(data->mlx_ptr, data->img.player_w);
	mlx_destroy_image(data->mlx_ptr, data->img.player_s);
	mlx_destroy_image(data->mlx_ptr, data->img.player_d);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
}

int	game_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window.win_ptr);
	free_map(data);
	free_all(data);
	exit(0);
	return (0);
}
