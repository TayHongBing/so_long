/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:32:04 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/12 16:19:15 by thong-bi         ###   ########.fr       */
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
	(void)argv;
	check_extension(argv[1]);
	data.map = read_map(argv[1]);
	if (data.map != NULL)
	{
		check_map(&data);
		initialize(&data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, data.width * 50,
				data.height * 50, "SO_LONG");
		render_map(&data);
		mlx_hook(data.win, 2, (1L << 0), key_hook, &data);
		mlx_hook(data.win, 17, (1L << 0), quit_game, &data);
		mlx_string_put(data.mlx, data.win, 5, 10, 0xffffff, "Move: 0");
		mlx_loop_hook(data.mlx, animation, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
