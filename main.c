/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:32:04 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/03 14:17:04 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
	{
		perror("ERROR");
		exit(1);
	}
	check_extension(argv[1]);
	data.map = read_map(argv[1]);
	if (data.map)
	{
		check_map(&data);
		initialize(&data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, data.width * 50,
				data.height * 50, "SO_LONG");
		render_map(&data);
		
	}
}
