/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:00 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/03 14:40:35 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_file/mlx.h"
# include "./gnl/get_next_line.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*win;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		move;
	char	**map;
	int		collect;
}	t_data;

typedef struct s_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map;

void	check_extension(char *file);
int		get_height(char **map);
char	**read_map(char *argv);
void	free_map(t_data *data, char **err);
void	check_map(t_data *data);
void	initialize(t_data *data);
void	render_map(t_data *data);