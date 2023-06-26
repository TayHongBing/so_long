/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:26:51 by thong-bi          #+#    #+#             */
/*   Updated: 2023/04/07 00:47:10 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_file/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./Libft/libft.h"

typedef struct s_img
{
	void	*img_p;
	void	*img_w;
	void	*img_c;
	void	*img_e;
	void	*img_s;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	int		height;
	int		width;

}	t_img;

typedef struct s_window
{
	void	*win_ptr;
	int		col;
	int		row;
	int		height;
	int		width;
	char	**map;
	int		player;
	int		coin;
	int		exit;
	int		end;
}	t_window;

typedef struct s_player
{
	int		player_direc;
	int		moves;
	int		x;
	int		y;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	t_img		img;
	t_window	window;
	t_player	player;
}	t_data;

# define SPRITE_SIZE 16

# define IMG_S "assets/floor.xpm"
# define IMG_E "assets/exit.xpm"
# define IMG_C "assets/coin.xpm"
# define IMG_W "assets/wall.xpm"
# define IMG_P "assets/player.xpm"
# define IMG_P_W "assets/player_w.xpm"
# define IMG_P_A "assets/player_d.xpm"
# define IMG_P_S "assets/player.xpm"
# define IMG_P_D "assets/player_a.xpm"
# define KEY_ESC 53
# define KEY_Q 53
# define KEY_W 13
# define KEY_A 2
# define KEY_S 1
# define KEY_D 0
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

char	**read_map(char *argv);
int		check_map(t_data *data, char **map, char *file);
void	img_draw(t_data *data, void	*img, int x, int y);
void	initializer(t_data *data);
void	update_location(int keycode, t_data *data);
void	update_direction(int keycode, t_data *data);
void	result_key(t_data *data, int j, int i);
void	updater(int keycode, t_data *data);
int		display_info(t_data *data);
int		game_exit(t_data *data);
void	free_map(t_data *data);
int		key_press(int keycode, t_data *data);
void	hook_all(t_data *data);
void	map_hook_p(t_data *data, int j, int i);

#endif
