/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:11:44 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/05 18:01:01 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *data)
{
	data->collect = 0;
	data->move = 0;
	data->width = ft_strlen(data->map[0]);
	data->height = get_height(data->map);
	data->e_data.sign = 1;
	data->e_data.x = 0;
	data->e_data.sleep = 5;
	data->e_data.sleep_for_move = 60;
	data->e_data.path = 0;
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

void	update_move(t_data ***data)
{
	int		width;
	int		height;
	char	*text;
	char	*num;

	num = ft_itoa(++(**data)->move);
	text = ft_join_strings("Move: ", num);
	(**data)->img = mlx_xpm_file_to_image((**data)->mlx, "./img/wall.xpm",
			&width, &height);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img, 0, 0);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img, 50, 0);
	mlx_put_image_to_window((**data)->mlx, (**data)->win, (**data)->img,
		50 * 2, 0);
	mlx_string_put((**data)->mlx, (**data)->win, 5, 10, 0xfffffff, text);
	printf("%s\n", num);
	free(text);
	free(num);
}

char	*ft_join_strings(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	char			*ptr;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1_len-- != 0)
		ptr[i++] = *s1++;
	while (s2_len-- != 0)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
