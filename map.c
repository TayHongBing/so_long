/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:29 by thong-bi          #+#    #+#             */
/*   Updated: 2023/07/05 18:16:50 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_message_error(void)
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

char	**read_map(char *argv)
{
	char	*tmp;
	char	*all;
	int		fd;

	tmp = "";
	all = ft_strdup("");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_message_error();
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL || tmp[0] == '\n')
			break ;
		all = ft_strjoin(all, tmp);
		free(tmp);
	}
	free(tmp);
	close(fd);
	if (all[0] == '\0')
		ft_message_error();
	return (ft_split(all, '\n'));
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
