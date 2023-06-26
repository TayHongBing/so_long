/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:17:26 by thong-bi          #+#    #+#             */
/*   Updated: 2023/06/26 15:11:08 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		data.window.map = read_map(argv[1]);
		if (check_map(&data, data.window.map, argv[1]))
		{
			initializer(&data);
			hook_all(&data);
			mlx_loop(data.mlx_ptr);
		}
		else
		{
			printf("\nERROR\nInvalid map!\n");
			free_map(&data);
			exit(1);
		}
	}
	else
	{
		printf("\nError: No map specified\n");
		exit(1);
	}
	return (0);
}
