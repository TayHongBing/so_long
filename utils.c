/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:11:44 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/03 14:13:46 by thong-bi         ###   ########.fr       */
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