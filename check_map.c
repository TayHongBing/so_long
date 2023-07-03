/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:09:49 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/03 14:09:43 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(t_data *data)
{
	int	y;
	int	x;
	int	height;
	int	check_x;

	y = 0;
	check_x = 0;
	height = get_height(data->map);
	while (y != height)
	{
		x = 0;
		while (data->map[y][x] != '\0')
			x++;
		y++;
		if (check_x != 0)
		{
			if (check_x != x)
				free_map(data, "Map is not rectangular!!");
		}
		else
			check_x = x;
	}
}

static void	check_walls(t_data *data)
{
	int		i;
	int		j;
	int		len;

	i = get_height(data->map) - 1;
	len = ft_strlen(data->map[0]);
	while (i)
	{
		j = 0;
		while (j < len)
		{
			if (data->map[0][j] != '1' || data->map[i][j] != 1 ||
				data->map[i][0] != '1' || data->map[i][len - 1] != '1')
				free_map(data, "Map is not surrounded by walls");
			j++;
		}
		i--;
	}
}

static void	check_elements(t_data *data)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height(data->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while (data->map[map.y][map.x] != '\0')
		{
			if (data->map[map.y][map.x] == 'E')
				map.e++;
			else if (data->map[map.y][map.x] == 'P')
				map.p++;
			else if (data->map[map.y][map.x] == 'C')
				map.c++;
			else if (data->map[map.y][map.x] != '1' &&
				data->map[map.y][map.x] != '0')
				free_map(data, "Unknown element!");
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		free_map(data, "Map element error!");
}

void	check_map(t_data *data)
{
	check_rectangular(data);
	check_elements(data);
	check_walls(data);
}
