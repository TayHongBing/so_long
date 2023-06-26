/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:40:54 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/31 03:44:59 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(t_data *data, char **map)
{
	int	i;
	int	j;

	data->window.col = ft_strlen(map[0]) - 1;
	data->window.row = 0;
	while (map[data->window.row])
		data->window.row++;
	i = 0;
	while (i < data->window.row)
	{
		j = 0;
		while (j < data->window.col)
		{
			if (map[0][j] != '1' || map[data->window.row - 1][j] != '1'
				|| map[i][0] != '1' || map[i][data->window.col - 1] != '1')
				return (0);
			j++;
		}
		if (j != data->window.col)
			return (0);
		i++;
	}
	return (1);
}

static int	check_counter(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				data->window.exit++;
			if (map[i][j] == 'P')
				data->window.player++;
			if (map[i][j] == 'C')
				data->window.coin++;
			j++;
		}
		i++;
	}
	if (data->window.exit != 1 || data->window.player != 1
		|| data->window.coin == 0)
		return (0);
	return (1);
}

static int	check_content(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->window.row)
	{
		j = 0;
		while (j < data->window.col - 1)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_extension(char *file)
{
	char	*extension;

	if (!file)
		return (0);
	extension = ft_strrchr(file, '.');
	if (ft_strncmp(extension, ".ber", 5))
		return (0);
	return (1);
}

int	check_map(t_data *data, char **map, char *file)
{
	data->window.coin = 0;
	data->window.exit = 0;
	data->window.player = 0;
	if (!(check_extension(file) && check_wall(data, map)
			&& check_counter(data, map) && check_content(data, map)))
		return (0);
	return (1);
}
