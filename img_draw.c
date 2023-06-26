/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:11:16 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/22 15:17:39 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_data *data, void	*img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->window.win_ptr, img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}
